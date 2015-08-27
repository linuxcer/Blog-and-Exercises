/*************************************************************************
 *  --------->    File Name: pipe_rule1.c
 *  --------->    Author: ChengfeiZH
 *  --------->    Mail: chengfeizh@gmail.com
 *  --------->    Time: 2015年08月27日 星期四 20时16分45秒
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
int main() {
    int pipe_fd[2];
    pid_t pid;
    char r_buf[4];
    char * w_buf;
    int writenum;
    int cmd;
    memset(r_buf, 0, sizeof(r_buf));
    if(pipe(pipe_fd) < 0) {
        printf("pipe create error\n");
        return -1;
    }

    if ((pid = fork()) == 0) {
        close(pipe_fd[0]);
        close(pipe_fd[1]);
        sleep(10);
        exit(0);
    } else if (pid > 0) {
        sleep(1);
        close(pipe_fd[0]);
        w_buf = "111";
        if ((writenum = write(pipe_fd[1], w_buf, 4)) == -1) {
            printf("write to pipe error\n");
        } else {
            printf("the bytes = %d\n", writenum);
        }
        close(pipe_fd[1]);
    }
    return 0;
}
