#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/stat.h>
#include <fcntl.h>

#define PORT 8080
#define VERSION "0.1"
#define HTTP_VERSION "1.0"

#define E_BAD_REQ	1000

#define BUFFSIZE 512
#define MAXPENDING 5

struct http_request {
	int sock;
};

struct responce_header {
	int code;
	char *header;
};

struct responce_header headers[] = {
	{ 200, 	"HTTP/" HTTP_VERSION " 200 OK\r\n"
		"Server: jhttpd/" VERSION "\r\n"},
	{0, 0},
};

struct error_messages {
	int code;
	char *msg;
};

struct error_messages errors[] = {
	{400, "Bad Request"},
	{404, "Not Found"},
};

static void
die(char *m)
{
	printf("%s\n", m);
	exit(1);
}


static int
send_header(struct http_request *req, int code)
{
	struct responce_header *h = headers;
	while (h->code != 0 && h->header!= 0) {
		if (h->code == code)
			break;
		h++;
	}

	if (h->code == 0)
		return -1;

	int len = strlen(h->header);
	if (write(req->sock, h->header, len) != len) {
		die("Failed to send bytes to client");
	}

	return 0;
}

static int
send_size(struct http_request *req, off_t size)
{
	char buf[64];
	int r;

	r = snprintf(buf, 64, "Content-Length: %ld\r\n", (long)size);
	if (r > 63)
		die("buffer too small!");

	if (write(req->sock, buf, r) != r)
		return -1;

	return 0;
}

static const char*
mime_type()
{
	return "text/html";
}

static int
send_content_type(struct http_request *req)
{
	char buf[128];
	int r;
	const char *type;

	type = mime_type();
	if (!type)
		return -1;

	r = snprintf(buf, 128, "Content-Type: %s\r\n", type);
	if (r > 127)
		die("buffer too small!");

	if (write(req->sock, buf, r) != r)
		return -1;

	return 0;
}

static int
send_header_fin(struct http_request *req)
{
	const char *fin = "\r\n";
	int fin_len = strlen(fin);

	if (write(req->sock, fin, fin_len) != fin_len)
		return -1;

	return 0;
}

static int
send_error(struct http_request *req, int code)
{
	char buf[512];
	int r;

	struct error_messages *e = errors;
	while (e->code != 0 && e->msg != 0) {
		if (e->code == code)
			break;
		e++;
	}

	if (e->code == 0)
		return -1;

	r = snprintf(buf, 512, "HTTP/" HTTP_VERSION" %d %s\r\n"
			       "Server: jhttpd/" VERSION "\r\n"
			       "Connection: close"
			       "Content-type: text/html\r\n"
			       "\r\n"
			       "<html><body><p>%d - %s</p></body></html>\r\n",
			       e->code, e->msg, e->code, e->msg);

	if (write(req->sock, buf, r) != r)
		return -1;

	return 0;
}

static int send_info(struct http_request *req)
{
	char buf[1024] = "<html><head><title>Index of </title></head><body>Hello World</body></html>";
	int n = sizeof(buf);
	write(req->sock, buf, n);
	return 0;
}

static int
send_data(struct http_request *req)
{
	int r;

	if ((r = send_header(req, 200)) < 0)
		goto end;

	if ((r = send_size(req, 1024)) < 0)
		goto end;

	if ((r = send_content_type(req)) < 0)
		goto end;

	if ((r = send_header_fin(req)) < 0)
		goto end;


	r = send_info(req);

end:
	return r;
}

static void
handle_client(int sock)
{
	struct http_request con_d;
	int r;
	char buffer[BUFFSIZE];
	int received = -1;
	struct http_request *req = &con_d;

	while (1)
	{
		if ((received = read(sock, buffer, BUFFSIZE)) < 0)
			die("failed to read");

		memset(req, 0, sizeof(req));
		req->sock = sock;
		send_data(req);
		break;
	}
	close(sock);
}

int main(int argc, char **argv)
{
	int serversock, clientsock;
	struct sockaddr_in server, client;
	
	if ((serversock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
		die("Failed to create socket");

	memset(&server, 0, sizeof(server));	
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	server.sin_port = htons(PORT);

	if (bind(serversock, (struct sockaddr *) &server,
		 sizeof(server)) < 0)
	{
		die("Failed to bind the server socket");
	}

	if (listen(serversock, MAXPENDING) < 0)
		die("Failed to listen on server socket");

	printf("Waiting for http connections...\n");

	while (1) {
		unsigned int clientlen = sizeof(client);
		if ((clientsock = accept(serversock,
					 (struct sockaddr *) &client,
					 &clientlen)) < 0)
		{
			die("Failed to accept client connection");
		}
		handle_client(clientsock);
	}

	close(serversock);
}
