/*************************************************************************
 *  --------->    FILE: memset.c
 *  --------->    AUTHOR: Aaron
 *  --------->    MAIL: chengfeizh@gmail.com
 *  --------->    DATE: 10/22/2015    TIME:19:03:03
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    memset(str, 'a', 100);
    str[99] = '\0';
    printf("%s\n", str);
    return 0;
}
