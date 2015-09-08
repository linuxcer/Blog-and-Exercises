/*************************************************************************
 *  --------->    FILE: partial_sum.cpp
 *  --------->    AUTHOR: Aaron
 *  --------->    MAIL: chengfeizh@gmail.com
 *  --------->    DATE: 09/08/2015    TIME:10:50:54
 ************************************************************************/

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    vector<int> tmp;
    tmp.push_back(1);
    tmp.push_back(3);
    tmp.push_back(8);
    vector<int> sum_from_start(3, 0);
    cout << sum_from_start[0] << "  " <<  sum_from_start[1] << "  " << sum_from_start[2] <<  endl;
    partial_sum(tmp.begin(), tmp.end(), sum_from_start.begin());
    cout << sum_from_start[0] << "  " <<  sum_from_start[1] << "  " << sum_from_start[2] <<  endl;
    return 0;
}

