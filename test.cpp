/*************************************************************************
 *  --------->    File Name: test.cpp
 *  --------->    Author: ChengfeiZH
 *  --------->    Mail: chengfeizh@gmail.com
 *  --------->    Time: 2015年08月16日 星期日 10时31分17秒
 ************************************************************************/

#include <iostream>
using namespace std;
void fiddle(int in1, int &in2) {
    in1 = in1 + 10;
    in2 = in2 + 10;
    cout << in1 << "   " << in2 << endl;
}

int main() {
    int v1 = 8, v2 = 12;
    cout << v1 << "   " << v2 << endl;
    fiddle(v1, v2);
    cout << v1 << "   " << v2 << endl;
    return 0;
}
