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
        return (fabs(k1 - k2) > 1e-2);
    }
};

int main() {
    map<double, int, cmp_key> Map;
    Map[69] += 1;
    map <double, int, cmp_key>::iterator it;
    it = Map.find(69);                                                                          
    if (it == Map.end()) { 
    //if (Map.find(69) == Map.end()) {
        cout << "ditn't equal" << endl;
    } else {
        cout << "equal" << endl;
    }
    return 0;
}
