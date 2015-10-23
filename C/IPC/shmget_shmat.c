/*************************************************************************
 *  --------->    FILE: shmget_shmat.c
 *  --------->    AUTHOR: Aaron
 *  --------->    MAIL: chengfeizh@gmail.com
 *  --------->    DATE: 10/23/2015    TIME:11:23:14
 ************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/time.h>
#define PERM S_IRUSR|S_IWUSR

int main(int argc,char **argv) {
    int shmid;
    char *p_addr,*c_addr;
    struct timeval start, end;
    if (argc != 2) {
        fprintf(stderr, "Usage：%s\n\a", argv[0]);
        exit(1);
    }

    if ((shmid = shmget(IPC_PRIVATE, 1024, PERM)) == -1) {
        fprintf(stderr,"Create Share Memory Error：%s\n\a", strerror(errno));
        exit(1);
    }

    if (fork()) {
        gettimeofday(&start, NULL);
        printf("start time: %ld\n", 1000000 * start.tv_sec + start.tv_usec);
        p_addr = shmat(shmid, 0, 0);
        memset(p_addr, '\0', 1024);
        strncpy(p_addr, argv[1], 1024);
        exit(0);
    } else {
        c_addr = shmat(shmid, 0, 0);
        gettimeofday(&end, NULL);
        printf("end time: %ld\n", 1000000 * end.tv_sec + end.tv_usec);
        printf("Client get %s\n", c_addr);
        exit(0);
    }
}
