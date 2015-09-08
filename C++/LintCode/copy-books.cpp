/*************************************************************************
 *  --------->    FILE: copy-books.cpp
 *  --------->    AUTHOR: Aaron
 *  --------->    MAIL: chengfeizh@gmail.com
 *  --------->    DATE: 09/08/2015    TIME:11:10:58
 ************************************************************************/

#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
    int copyBooks(vector<int> &pages, int k) {
        int n = pages.size();
        k = min(n, k);

        vector<int> sum_from_start(n, 0);
        partial_sum(pages.begin(), pages.end(), sum_from_start.begin());

        vector<vector<int> > minites(k + 1, vector<int>(n, INT_MAX)); // minites start from 1 not 0


        for (int i = 1; i <= k; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 1 || j == 0) {
                    minites[i][j] = sum_from_start[j];
                } else {
                    for (int t = j - 1; t >= 0; t--) {
                        int curr = max(minites[i - 1][t], sum_from_start[j] - sum_from_start[t]);
                        minites[i][j] = min(curr, minites[i][j]);
                    }
                }
            }
        }
        return minites[k][n - 1];
   }
}


int main() {
    return 0;
}

