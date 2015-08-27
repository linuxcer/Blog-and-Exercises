/*************************************************************************
 *  --------->    File Name: main.c
 *  --------->    Author: ChengfeiZH
 *  --------->    Mail: chengfeizh@gmail.com
 *  --------->    Time: 2015年08月14日 星期五 09时18分53秒
 ************************************************************************/
#include <string.h>
#include <stdio.h>
int fun(int x)
{
    int countx = 0;
    while (x)
    {
        countx++;
        x = x & (x - 1);
    }
    return countx;
}
print_value(int *x) {
    printf("%x\n", ++*x);

}

int foo(int x, int y) {
    if(x <= 0 || y <= 0) {
        return 1;
    }
    return 3 * foo(x - 6, y/2);
}
struct T {
   char a;
   int *d;
   int b;
   int c:16;
   double e;

};
struct T *p;
#ifndef F
#define F 0
#endif

int main(int argc, char **argv) {
  //  int a = 25;
//    print_value(&a);
//    printf("%p   --->   %p\n", p, p + sizeof(*p));
    //#ifdef F
    //printf("hello world\n");
    //#endif
    char *p = "zhang";
    char ch = *p++;
    printf("%c", ch);
    return 0;
}
