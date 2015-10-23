/*************************************************************************
 *  --------->    FILE: exit_wait.c
 *  --------->    AUTHOR: Aaron
 *  --------->    MAIL: chengfeizh@gmail.com
 *  --------->    DATE: 10/23/2015    TIME:09:50:09
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

int main(int argc, char *argv[]) {
    pid_t pid, pr;
    struct timeval start, end;
    pid  = fork();
    if (pid < 0) {
        printf("fork error\n");
    } else if (pid == 0) {
        gettimeofday(&start, NULL);
        printf("start time: %ld\n", 1000000 * start.tv_sec + start.tv_usec);
        exit(0);
    } else {
        pr = wait(NULL);
        gettimeofday(&end, NULL);
        printf("end time: %ld\n", 1000000 * end.tv_sec + end.tv_usec);
        printf("I cached a child process with pid of %d\n", pr);
    }
    return 0;
}
