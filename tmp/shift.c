/*************************************************************************
 *  --------->    FILE: shift.c
 *  --------->    AUTHOR: Aaron
 *  --------->    MAIL: chengfeizh@gmail.com
 *  --------->    DATE: 09/16/2015    TIME:08:40:25
 ************************************************************************/

#include <stdio.h>
int main() {
    char str[10] = "zhang";
    int i;
    goto end;
    printf("%p\n", str);
    printf("%p\n", (long)str & 0xfffffffffffff000);
    int start = 0;
    /*
    for (i = 0; i < 4096; i++) {
        if (*(char *)(((unsigned long)str & 0xfffffffffffff000) + i) == 'z') {
            start = 1;
            printf("%d %c\n", i, * (char *)(((unsigned long)str & 0xfffffffffffff000) + i));
        }
        if (start == 1) {
            printf("%c", * (char *)(((unsigned long)str & 0xfffffffffffff000) + i));
        }
    }*/
end:
    printf("end\n");

    return 0;
}
