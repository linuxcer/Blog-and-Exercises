/*************************************************************************
 *  --------->    FILE: clone.c
 *  --------->    AUTHOR: Aaron
 *  --------->    MAIL: chengfeizh@gmail.com
 *  --------->    DATE: 09/01/2015    TIME:10:00:42
 ************************************************************************/

#include <stdio.h>
#include <sched.h>
#include <unistd.h>
#include <signal.h>

void *stack;

void fun() {
    printf("---> in fun\n");
}
int main() {
    int pid;
    if ((pid == fork()) == 0) {
        printf("in child\n");
        execl("./pro1.out","",(char *)0);
        printf("-------------->\n");
    } else {
        //clone(fun, (char *)stack + 8192, CLONE_VFORK, 0);
        printf("in parent\n");
        
    }
}
