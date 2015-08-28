/*************************************************************************
 *  --------->    File Name: signal.c
 *  --------->    Author: ChengfeiZH
 *  --------->    Mail: chengfeizh@gmail.com
 *  --------->    Time: 2015年08月27日 星期四 22时30分08秒
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    int status;
    if (!(pid = fork())) {
        printf("Hi I am child process\n");
        sleep(10);
        return;
    } else {
        printf("send signal to child process (%d)\n", pid);
        sleep(1);
        kill(pid, SIGABRT);
        wait(&status);
        if(WIFSIGNALED(status)) {
            printf("child process receive signal %d\n", WTERMSIG(status));
        }
    }
    return 0;
}
