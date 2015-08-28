/*************************************************************************
 *  --------->    File Name: alarm.c
 *  --------->    Author: ChengfeiZH
 *  --------->    Mail: chengfeizh@gmail.com
 *  --------->    Time: 2015年08月28日 星期五 15时00分47秒
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
void handler() {
    printf("hello\n");
}

int main() {
    int i; 
    signal(SIGALRM, handler);
    alarm(5);
    for (i = 1; i < 7; i++) {
        printf("sleep %d ... \n", i);
        sleep(1);
    }
    return 0;
}
