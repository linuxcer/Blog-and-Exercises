/*************************************************************************
 *  --------->    FILE: kill.c
 *  --------->    AUTHOR: Aaron
 *  --------->    MAIL: chengfeizh@gmail.com
 *  --------->    DATE: 08/31/2015    TIME:09:09:52
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <assert.h>
#include <stdlib.h>
#include <sys/time.h>

int main() {
    pid_t pid;
    int status;
    struct timeval start, end;
    pid  = fork();
    assert(pid >= 0);
    if (pid  == 0) {
        printf("child process!\n");
        gettimeofday(&start, NULL);
        kill(0, SIGKILL);
        sleep(5);
        printf("status3\n");
    } else if (pid > 0) {
        sleep(4);
        printf("status1 pid = %d\n", pid);
        sleep(9);
        printf("status2\n");
    }
    return 0;
}
