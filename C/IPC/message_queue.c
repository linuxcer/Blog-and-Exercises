/*************************************************************************
 *  --------->    FILE: message_queue.c
 *  --------->    AUTHOR: Aaron
 *  --------->    MAIL: chengfeizh@gmail.com
 *  --------->    DATE: 10/23/2015    TIME:09:19:03
 ************************************************************************/
/*
本程序主要功能是实现两个进程间的通过信息队列来传输数据

*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h> 
#include <sys/time.h>

struct msgbuf
{
    long mtype;       /* message type, must be > 0 */
    char mtext[255];    /* message data */
};


int main()
{
    pid_t pid ; 

    key_t key ; 
    int messageID ;   //消息队列符号
    struct msgbuf sndmsg ;  
    struct msgbuf rcvmsg ;         

    key = ftok("." ,1) ;
    messageID = msgget(key ,IPC_CREAT | 0666) ;  //获取消息队列的ID 
    memset(&sndmsg ,0 ,sizeof(struct msgbuf)) ;  //清空

    struct timeval start, end;
    sndmsg.mtype = getpid() ;   //将父进程的ID赋给消息类型 
    strcpy(sndmsg.mtext ,"hello test data ") ; 
    pid = fork() ;  //创建一个子进程
    
    if(pid == 0 )
    {
        //子进程
        //从消息队列中接收消息,如果消息队列为空，则返回打印相关信息，否则打印接收到的消息
        printf("%d子进程\n" ,getpid() ) ;

        if(rcvmsg.mtext == " ")
        {
            printf("消息队列为空，没有消息\n") ;
        }
        else
        {
            //清空rcvmsg 
            memset(&rcvmsg ,0 ,sizeof(struct msgbuf))  ; 
            if(msgrcv(messageID ,&rcvmsg ,sizeof(struct msgbuf) ,sndmsg.mtype ,IPC_NOWAIT) == -1 )
            {
                fprintf(stderr ,"msgrcv errno :%d\n",errno) ; 
            }
            else
            {
                printf("接收到的消息是：%s\n" ,rcvmsg.mtext) ; 
                gettimeofday(&end, NULL);
                printf("end time : %ld\n", 1000000 * end.tv_sec + end.tv_usec);
            }
        }
    }
    else
    {
        //父进程  
        //把消息发送到消息队列中去
        printf("%d父进程\n" ,getpid() ) ;
        gettimeofday(&start, NULL);
        printf("start time : %ld\n", 1000000 * start.tv_sec + start.tv_usec);
        if(msgsnd(messageID ,&sndmsg ,sizeof(struct msgbuf) ,IPC_NOWAIT )  == -1)
        {
            fprintf(stderr ,"msgsnd errno :%d",errno) ; 
        } 
        else
        {
            printf("发送成功\n") ; 
        }
    }

    return 0 ; 
}
