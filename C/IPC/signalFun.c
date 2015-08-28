/*************************************************************************
 *  --------->    FILE: signalFun.c
 *  --------->    AUTHOR: Aaron
 *  --------->    MAIL: chengfeizh@gmail.com
 *  --------->    DATE: 08/28/2015    TIME:15:50:22
 ************************************************************************/

#include <stdio.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void func(int sign_no) {
    if (sign_no == SIGINT) {
        printf("Get SIGINT\n");
    } else if (sign_no == SIGQUIT) {
        printf("Get SIGQUIT\n");
    } 
}

int main() {
    printf("Waiting for signal SIGINT or SIGQUIT\n");
    signal(SIGINT, func);
    signal(SIGQUIT, func);
    pause();
    exit(0);
}
