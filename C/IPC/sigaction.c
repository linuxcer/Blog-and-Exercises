/*************************************************************************
 *  --------->    FILE: sigaction.c
 *  --------->    AUTHOR: Aaron
 *  --------->    MAIL: chengfeizh@gmail.com
 *  --------->    DATE: 08/28/2015    TIME:16:58:44
 ************************************************************************/
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
void show_handler(int tmp) {
    //(*(int*)&act->sa_flags);
    if (tmp == SIG_DFL) {
        printf("Default action \n"); 
    } else if(tmp == SIG_IGN) {
        printf("Ignore thre signal\n");
    } else {
       // printf("0x%x\n", act->sa_handler);
    }
    /*switch (act->sa_flags) {
        case SIG_DFL:printf("Default action \n"); break;
        case SIG_IGN:printf("Ignore the signal\n"); break;
        default: printf("0x%x\n", act->sa_handler);
    }*/
}

int main() {
    int i;
    struct sigaction act, oldact;
    act.sa_handler = show_handler;
    act.sa_flags = SA_ONESHOT | SA_NOMASK;
    sigaction(SIGUSR1, &act, &oldact);
    for (i = 5; i < 15; i++) {
        printf("hander of signal %2d = ", i);
        sigaction(i, NULL, &oldact);
    }
    return 0;
}
