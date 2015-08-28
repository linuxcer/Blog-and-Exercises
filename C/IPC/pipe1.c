/*************************************************************************
 *  --------->    File Name: pipe1.c
 *  --------->    Author: ChengfeiZH
 *  --------->    Mail: chengfeizh@gmail.com
 *  --------->    Time: 2015年08月26日 星期三 22时05分45秒
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
int main() {
    int filedes[2];
    char buffer[20];
    pipe(filedes);
    if(fork() > 0) {
        // father process
        char s[] = "hello\n";
        printf("sizeof = %d, strlen = %d\n", sizeof(s), strlen(s));
        write(filedes[1], s, sizeof(s));
    } else {
        // child
        read(filedes[0], buffer, 80);
        printf("child process RCV = %s\n", buffer);
    }
    return 0;
}
