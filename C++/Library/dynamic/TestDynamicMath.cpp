/*************************************************************************
 *  --------->    FILE: TestDynamicLibrary.cpp
 *  --------->    AUTHOR: Aaron
 *  --------->    MAIL: chengfeizh@gmail.com
 *  --------->    DATE: 08/31/2015    TIME:20:46:19
 ************************************************************************/
#include <cstdlib>
#include "DynamicMath.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    double a = 10;
    double b = 2;
    cout << "a + b = " << DynamicMath::add(a, b) << endl;
    cout << "a - b = " << DynamicMath::sub(a, b) << endl;
    cout << "a * b = " << DynamicMath::mul(a, b) << endl;
    cout << "a / b = " << DynamicMath::div(a, b) << endl;

    return 0;
}

