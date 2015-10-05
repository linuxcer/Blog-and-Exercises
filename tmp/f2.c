/*************************************************************************
	> File Name: f2.c
	> Author: 
	> Mail: 
	> Created Time: 2015年06月24日 星期三 00时09分05秒
 ************************************************************************/
#include<stdio.h>
#include "f1.h"
extern void fun(int);
int main() {
//    fun(1000);

    printf("%lu  %lu", sizeof(int), sizeof(float));
    return 0;
}
