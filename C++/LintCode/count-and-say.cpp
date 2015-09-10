/*************************************************************************
 *  --------->    FILE: count-and-say.cpp
 *  --------->    AUTHOR: Aaron
 *  --------->    MAIL: chengfeizh@gmail.com
 *  --------->    DATE: 09/10/2015    TIME:22:30:04
 ************************************************************************/

#include <iostream>
#include <sstream>
#include <string>
using namespace std;
class data {
public:    
    int value;
    int count;
    data() { value = 0; count = 0;}
};

class Solution {
public:
    /**
     * @param n the nth
     * @return the nth sequence
     */
    string countAndSay(int n) {
        // Write your code here
        string ss;
        stringstream sss;
        int sum = 1;
        data Data[100];
        int flag = 0;
        for (int i = 1; i < n; i++) {
            flag = 0;
            // store data
            while (sum != 0) {
                if (flag > 0 && Data[flag - 1].value == sum % 10) {
                    Data[flag - 1].count++;
                    sum = sum / 10;
                } else {
                    Data[flag].value = sum % 10;
                    Data[flag].count++;
                    sum = sum / 10;
                    flag++;
                }
            }

            // restore data
            while (flag) {
                flag--;
                sum = Data[flag].count;
                sum = sum * 10 + Data[flag].value;
            }
        }
        sss << sum;
        sss >> ss;
        return ss;
    }
};


int main() {
    Solution s;
    cout << s.countAndSay(5) << endl;
    return 0;
}
