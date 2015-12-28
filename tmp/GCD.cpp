/*************************************************************************
 *  --------->    FILE: GCD.cpp
 *  --------->    AUTHOR: Aaron
 *  --------->    MAIL: chengfeizh@gmail.com
 *  --------->    DATE: 12/08/2015    TIME:11:41:11
 ************************************************************************/

#include <iostream>
using namespace std;

int GCD(int m, int n) {
    if (m % n != 0) {
        return GCD(n, (m % n));
    } else {
        return n;
    }
}

int main () {
    int m, n;
    cin >> m >> n; 
    if (m < n) {
        int tmp = n;
        n = m;
        m = tmp;
    }
    cout << GCD(m, n);
}
