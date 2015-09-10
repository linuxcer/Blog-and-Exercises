/*************************************************************************
 *  --------->    FILE: length-of-last-word.cpp
 *  --------->    AUTHOR: Aaron
 *  --------->    MAIL: chengfeizh@gmail.com
 *  --------->    DATE: 09/09/2015    TIME:19:23:50
 ************************************************************************/

#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string &s) {
        int len = s.length();
        cout << len << endl;
        int count = 0;
        for (int i = len - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                count++;
            } else {
                return count;
            }
        }
        return count;
    }
};

int main() {
    Solution s;
    string str = "hello world";
    cout << s.lengthOfLastWord(str) << endl;
    return 0;
}
