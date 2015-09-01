/*************************************************************************
 *  --------->    FILE: signaction1.c
 *  --------->    AUTHOR: Aaron
 *  --------->    MAIL: chengfeizh@gmail.com
 *  --------->    DATE: 08/31/2015    TIME:11:17:49
 ************************************************************************/

/*
 * run : ./sigaction1 2
 * receive signal : Ctrl + C
 * quit : Ctrl + \
 **/


#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

void fun(int signum, siginfo_t *info, void *myact) {
    printf("receive signal %d\n", signum);
    sleep(5);
}

int main(int argc, char **argv) {
    struct sigaction act;
    int sig;
    sig = atoi(argv[1]);
    sigemptyset(&act.sa_mask);
    act.sa_sigaction = fun;
    if (sigaction(sig, &act, NULL) < 0) {
        perror("install sigal error\n");
        return -1;
    }
    while (1) {
        sleep(2);
        printf("wait for the sinals\n");
    }

    return 0;
}
