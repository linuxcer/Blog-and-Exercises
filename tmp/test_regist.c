/*************************************************************************
 *  --------->    FILE: test_regist.c
 *  --------->    AUTHOR: Aaron
 *  --------->    MAIL: chengfeizh@gmail.com
 *  --------->    DATE: 10/09/2015    TIME:09:17:14
 ************************************************************************/

#include<stdio.h>
int fun(int x) {
    int i = x;
    i ++;
    printf("%d\n", i);
}

int main() {
    int i = 10;
    fun(i);
    return 0;
}
