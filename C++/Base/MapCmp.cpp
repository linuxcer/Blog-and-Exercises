/*************************************************************************
 *  --------->    FILE: MapCmp.cpp
 *  --------->    AUTHOR: Aaron
 *  --------->    MAIL: chengfeizh@gmail.com
 *  --------->    DATE: 09/01/2015    TIME:20:55:02
 ************************************************************************/

#include <iostream>
#include <map>
#include <cmath>
using namespace std;

// return false means equal else not equal 
struct cmp_key {
    bool operator()(const double &k1, const double &k2) const {
        return (fabs(k1 - k2) > 1e-8);
    }
};

int main() {
    map<double, int, cmp_key> Map;
    Map[0.0000000002] = 1;
    if (Map.find(0.0000000001) == Map.end()) {
        cout << "ditn't equal" << endl;
    } else {
        cout << "equal" << endl;
    }
    return 0;
}
