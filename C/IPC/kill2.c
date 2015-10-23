/*************************************************************************
 *  --------->    FILE: kill2.c
 *  --------->    AUTHOR: Aaron
 *  --------->    MAIL: chengfeizh@gmail.com
 *  --------->    DATE: 10/23/2015    TIME:10:53:22
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>

main()
{
    pid_t pid;
    int status;
    struct timeval start, end;
    if(!(pid= fork()))
    {
        printf("Hi I am child process!\n");
        sleep(10);
        return;
    }
    else
    {
        printf("send signal to child process (%d) \n", pid);
        gettimeofday(&start, NULL);
        printf("start time: %ld\n", 1000000 * start.tv_sec + start.tv_usec);
        kill(pid, SIGABRT);
        wait(&status);
        if(WIFSIGNALED(status)) {
            gettimeofday(&end, NULL);
            printf("end time: %ld\n", 1000000 * end.tv_sec + end.tv_usec);
            printf("chile process receive signal %d\n", WTERMSIG(status));
        }
    }
}
