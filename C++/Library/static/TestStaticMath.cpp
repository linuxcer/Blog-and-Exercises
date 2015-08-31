/*************************************************************************
 *  --------->    FILE: TestStaticLibrary.cpp
 *  --------->    AUTHOR: Aaron
 *  --------->    MAIL: chengfeizh@gmail.com
 *  --------->    DATE: 08/31/2015    TIME:20:46:19
 ************************************************************************/
#include <cstdlib>
#include "StaticMath.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    double a = 10;
    double b = 2;
    cout << "a + b = " << StaticMath::add(a, b) << endl;
    cout << "a - b = " << StaticMath::sub(a, b) << endl;
    cout << "a * b = " << StaticMath::mul(a, b) << endl;
    cout << "a / b = " << StaticMath::div(a, b) << endl;

    system("pause");
    return 0;
}

