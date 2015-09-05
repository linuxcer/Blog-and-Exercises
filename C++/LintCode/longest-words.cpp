/*************************************************************************
 *  --------->    FILE: longest-words.cpp
 *  --------->    AUTHOR: Aaron
 *  --------->    MAIL: chengfeizh@gmail.com
 *  --------->    DATE: 09/05/2015    TIME:15:54:16
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    /**
     * @param dictionary: a vector of strings
     * @return: a vector of strings
     */
    vector<string> longestWords(vector<string> &dictionary) {
        // write your code here

        vector<string> str;
        int max = 0;
        int length = 0;
        for (int i = 0; i < dictionary.size(); ++i) {
            length = dictionary[i].length();
            if (length > max) {
                max = length;
                str.clear();
                str.push_back(dictionary[i]);
            } else if (length == max) {
                str.push_back(dictionary[i]);
            }
        }
        return str;
    }
};


int main() {
    vector<string> v;
    v.push_back("dog");
    v.push_back("google");
    v.push_back("facebook");
    Solution s;
    s.longestWords(v);
    return 0;
}
