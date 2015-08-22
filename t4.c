/*************************************************************************
 *  --------->    File Name: t4.c
 *  --------->    Author: ChengfeiZH
 *  --------->    Mail: chengfeizh@gmail.com
 *  --------->    Time: 2015年08月22日 星期六 09时10分45秒
 ************************************************************************/

#include <stdio.h>
int main() {
    
    int max = -999999999, min = 9999999999999;
    find(t, max, min);
}

void find(treenode *t, int &max, int &min) {
    if (t->data > max) {
        max = t->data;
    }
    if (t->data < min) {
        min = t->data;
    }
    if (t->left != NULL) {
        find(t->left, max, min);
    }
    if (t->right != NULL) {
        find(t->right, max, min);
    }
}
