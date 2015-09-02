/*************************************************************************
 *  --------->    FILE: space-replacement.cpp
 *  --------->    AUTHOR: Aaron
 *  --------->    MAIL: chengfeizh@gmail.com
 *  --------->    DATE: 09/01/2015    TIME:21:27:26
 ************************************************************************/

#include <iostream>
#include <string.h>
using namespace std;

class Solution {
public:
    int replaceBlank(char string[], int length) {
	    if (length == 0) {
            return NULL;
        }
        cout << string << "  " << length << endl;
        int count = 0; // count the space number
        for (int i = 0; i < length; ++i) {
            if (string[i] == ' ') {
                count ++;
            }
        }
        cout << count << endl;
        int new_length = length + 2 * count;
        cout << new_length << endl;
        for (int i = new_length, j = length; i >= 0, j>=0; j--) {
            if (string[j] != ' ') {
                string[i--] = string[j];
            } else {
                string[i--] = '0';
                string[i--] = '2';
                string[i--] = '%';
            }
            
        }
	return new_length;
    }
};

int main() {
    char str[1024] = "Mr John Smith";
    int length = strlen(str);
    Solution s;
    s.replaceBlank(str, length);
    cout << "result :" << str << endl;
    return 0;
}
