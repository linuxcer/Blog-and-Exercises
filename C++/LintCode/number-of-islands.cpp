/*************************************************************************
 *  --------->    FILE: number-of-islands.cpp
 *  --------->    AUTHOR: Aaron
 *  --------->    MAIL: chengfeizh@gmail.com
 *  --------->    DATE: 09/07/2015    TIME:21:09:43
 ************************************************************************/
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    /**
     * @param grid a boolean 2D matrix
     * @return an integer
     */
    int numIslands(vector<vector<bool> >& grid) {
        // Write your code here
        int raws = grid.size();
        if (raws == 0) {
            return 0;
        }
        int cols = grid[0].size();
        if (cols == 0) {
            return 0;
        }
        int num = 0;
        if (raws == 0 || cols == 0) {
            return 0;
        } 
        for (int i = 0; i < raws; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    num++;
                    DFS(grid, i, j);
                }
            }
        }
        
        return num;
    }
    
    
    int X[4] = {0, 0, -1, 1};
    int Y[4] = {1, -1, 0, 0};
    void DFS(vector<vector<bool> >& grid, int i, int j) {
        // traverse four directions and set 1 to 0
        grid[i][j] = 0;
        for (int k = 0; k < 4; k++) {
            int nextX = i + X[k];
            int nextY = j + Y[k];
            if (nextX < grid.size() && nextY < grid[0].size() && grid[nextX][nextY] == 1) {
                DFS(grid, nextX, nextY);
            }
        }
    }
};

int main() {
    vector<vector<bool> > grid;
    vector<bool> a;
    vector<bool> b;
    vector<bool> c;
    vector<bool> d;
    vector<bool> e;

    a.push_back(1);
    a.push_back(1);
    a.push_back(0);
    a.push_back(0);
    a.push_back(0);

    b.push_back(0);
    b.push_back(1);
    b.push_back(0);
    b.push_back(0);
    b.push_back(1);

    c.push_back(0);
    c.push_back(0);
    c.push_back(0);
    c.push_back(1);
    c.push_back(1);

    d.push_back(0);
    d.push_back(0);
    d.push_back(0);
    d.push_back(0);
    d.push_back(0);

    e.push_back(0);
    e.push_back(0);
    e.push_back(0);
    e.push_back(0);
    e.push_back(1);
    grid.push_back(a);
    grid.push_back(b);
    grid.push_back(c);
    grid.push_back(d);
    grid.push_back(e);

    Solution s;

    cout << s.numIslands(grid) << endl;
    return 0;
}
