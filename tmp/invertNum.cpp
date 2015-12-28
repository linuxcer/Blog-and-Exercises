/*************************************************************************
 *  --------->    FILE: invertNum.cpp
 *  --------->    AUTHOR: Aaron
 *  --------->    MAIL: chengfeizh@gmail.com
 *  --------->    DATE: 12/08/2015    TIME:10:59:46
 ************************************************************************/

#include <iostream>
using namespace std;
void invert(int num) {
    if (num < 10) {
        cout << num;
    } else {
        cout << num%10;
        invert(num/10);
    }
}

int main() {
    int input;
    cin >> input;
    invert(input);
    return 0;
}
