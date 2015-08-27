/*************************************************************************
	> File Name: test.c
	> Author: 
	> Mail: 
	> Created Time: 2015年04月10日 星期五 12时54分27秒
 ************************************************************************/

#include<stdio.h>
#include <stdio.h>
#include <event.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdint.h>
#include <fcntl.h>
#include <stdlib.h>

static struct event clockevent;
struct event_base *main_base;
static void clock_handler(const int fd, const short which, void *arg)
{
        struct timeval t = {.tv_sec = 1, .tv_usec = 0 };
        static bool initialized = false;
        if(initialized){
                evtimer_del(&clockevent);
        }else{
                initialized = true;
        }
        evtimer_set(&clockevent, clock_handler, 0);
        event_base_set(main_base, &clockevent);
        evtimer_add(&clockevent, &t);
        printf("current_time: \n");
}
int main()
{
        main_base = event_init();
        clock_handler(0, 0, 0);
        event_base_loop(main_base, 0);

        return 0;
}
