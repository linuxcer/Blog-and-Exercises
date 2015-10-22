/*************************************************************************
 *  --------->    FILE: test_void_copy_value.c
 *  --------->    AUTHOR: Aaron
 *  --------->    MAIL: chengfeizh@gmail.com
 *  --------->    DATE: 10/19/2015    TIME:10:06:59
 ************************************************************************/

#include<stdio.h>
int main() {
    void * receive_page;
    char str[20] = "zhangchengfei";
    receive_page = str;
    printf("%s\n", receive_page);
    *((char *)receive_page + 4) = 'i';
    printf("%s\n", receive_page);
    return 0;
}
