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

int fun1() {
    printf("in fun1\n");
//    abort();
    exit(1);
}

int fun2() {
    printf("in fun2\n");
    abort();
}

int main() {
    pid_t pid;
    int status;
    pid  = fork();
    assert(pid >= 0);
    if (pid  == 0) {
        printf("child process!\n");
        fun1();
        sleep(2);
        printf("status3\n");
    } else if (pid > 0) {
        sleep(1);
        printf("status1 pid = %d\n", pid);
        fun2();
        sleep(2);
        printf("status2\n");
    }
    return 0;
}
