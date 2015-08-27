/*************************************************************************
 *  --------->    File Name: search.c
 *  --------->    Author: ChengfeiZH
 *  --------->    Mail: chengfeizh@gmail.com
 *  --------->    Time: 2015年08月20日 星期四 11时11分07秒
 ************************************************************************/

#include <stdio.h>
void search(char *a, int low, int high)
{
    int mid;
    if(low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid] < mid)
        {
            search(a, low, a[mid] - 1);
            search(a, mid + 1, high);
        } else if (a[mid] > mid)
        {
            search(a, a[mid] + 1, high);
            search(a, low, mid - 1);
        } else {
            if (low <= high){
                printf("%d  ", mid);
                search(a, low, mid - 1);
                search(a, mid + 1, high);
            }
        }
    }
}

int main()
{
//    char a[10] = {0, 1};
  //  search(a, 0, 2 - 1);
    char b[10] = {0, 3, 3, 3, 5, 5, 6};
    search(b, 0, 7 - 1);
    return 0;
}

