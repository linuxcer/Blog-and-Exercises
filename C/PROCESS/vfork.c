/*************************************************************************
 *  --------->    FILE: vfork.c
 *  --------->    AUTHOR: Aaron
 *  --------->    MAIL: chengfeizh@gmail.com
 *  --------->    DATE: 09/01/2015    TIME:08:38:36
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main() {
    int num = 1;
    int pid;
    if ((pid = fork()) == 0) {
        printf("Child, num = %d\n", ++num);
        sleep(4);
        printf("Child Over\n");
        _exit(1);
    } else {
        printf("Parent, num = %d\n", num);
        sleep(1);
        printf("Parent Over\n");
    }
    return 0;
}
