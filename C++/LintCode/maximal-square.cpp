/*************************************************************************
 *  --------->    FILE: maximal-square.cpp
 *  --------->    AUTHOR: Aaron
 *  --------->    MAIL: chengfeizh@gmail.com
 *  --------->    DATE: 09/07/2015    TIME:20:09:34
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    /**
     * @param matrix: a matrix of 0 and 1
     * @return: an integer
     */
    int maxSquare(vector<vector<int> > &matrix) {
        // write your code here
        if (matrix.size() == 0) {
            return 0;
        } else {
            int raws = matrix.size();
            int cols = matrix[0].size();
            int dp[raws][cols];
            int MAX = 0;
            for (int i = 0; i < raws; i++) {
                for (int j = 0; j < cols; j++) {
                    if (i == 0 || j == 0 || matrix[i][j] == 0) {
                        dp[i][j] = matrix[i][j];
                        MAX = max(dp[i][j], MAX);
                    } else {
                        dp[i][j] = min(min(dp[i - 1][j - 1], dp[i][j - 1]), dp[i - 1][j]) + 1;
                        MAX = max(dp[i][j], MAX);
                    }
                }
            }
            return MAX * MAX;
        }
    }
};

int main() {
    Solution s;
    vector<vector<int> > v;
    vector<int> a;
    vector<int> b;
    a.push_back(0);
    a.push_back(0);
    a.push_back(0);
    a.push_back(0);
    b.push_back(0);
    b.push_back(0);
    b.push_back(0);
    b.push_back(0);
    v.push_back(a);
    v.push_back(b);
    cout << s.maxSquare(v) << endl;
    return 0;
}
