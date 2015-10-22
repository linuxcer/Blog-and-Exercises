/*************************************************************************
 *  --------->    FILE: timer.c
 *  --------->    AUTHOR: Aaron
 *  --------->    MAIL: chengfeizh@gmail.com
 *  --------->    DATE: 10/22/2015    TIME:09:33:06
 ************************************************************************/

#include <stdio.h>
#include <sys/time.h>

int main() {
    struct timeval start, end;
    gettimeofday( &start, NULL );
    printf("start:%ld\n", start.tv_sec * 1000000 + start.tv_usec);
    sleep(3);
    gettimeofday( &end, NULL );
    printf("end:%ld\n", end.tv_sec * 1000000 + end.tv_usec);
    int timeuse = 1000000 * ( end.tv_sec - start.tv_sec ) + end.tv_usec -start.tv_usec;
    printf("time: %d us\n", timeuse);
    return 0;
}
