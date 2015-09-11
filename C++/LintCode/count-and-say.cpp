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
        string currstring = "1";
        for (int i = 1; i < n; i++) {
            char tmp = currstring[0];
            int count = 1;

            string tmpstring;
            // 处理边界条件
            currstring += "$";


            stringstream stream;
            string str;

            for (int j = 1; j < currstring.length(); j++) {
                if (tmp == currstring[j]){
                    count++;
                } else {
                    stream << count;
                    stream >> str;
                    tmpstring += str;
                    tmpstring += tmp;

                    tmp = currstring[j];
                    count = 1;
                }
            }
            currstring = tmpstring;
        }
        return currstring;
    }
};


int main() {
    Solution s;
    cout << s.countAndSay(4) << endl;
    cout << s.countAndSay(5) << endl;
    cout << s.countAndSay(6) << endl;
    return 0;
}
