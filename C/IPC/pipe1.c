/*************************************************************************
 *  --------->    File Name: pipe1.c
 *  --------->    Author: ChengfeiZH
 *  --------->    Mail: chengfeizh@gmail.com
 *  --------->    Time: 2015年08月26日 星期三 22时05分45秒
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>

int main() {
    int filedes[2];
    char buffer[20];
    pipe(filedes);
    struct timeval start, end;
    
    if(fork() > 0) {
        // father process
        char s[] = "hello\n";
        printf("sizeof = %ld, strlen = %d\n", sizeof(s), strlen(s));
        gettimeofday(&start, NULL);
        printf("start: %ld\n", start.tv_sec * 1000000 + start.tv_usec);
        write(filedes[1], s, sizeof(s));
    } else {
        // child
        read(filedes[0], buffer, 80);
        gettimeofday(&end, NULL);
        printf("end: %ld\n", end.tv_sec * 1000000 + end.tv_usec);
        printf("child process RCV = %s\n", buffer);
    }
    return 0;
}
