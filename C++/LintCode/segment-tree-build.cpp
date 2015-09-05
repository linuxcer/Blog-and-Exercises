/*************************************************************************
 *  --------.    FILE: segment-tree-build.cpp
 *  --------.    AUTHOR: Aaron
 *  --------.    MAIL: chengfeizh@gmail.com
 *  --------.    DATE: 09/05/2015    TIME:11:26:13
 ************************************************************************/

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
class SegmentTreeNode {
public:
    int start, end, max;
    SegmentTreeNode *left, *right;
    SegmentTreeNode(int start, int end, int max) {
        this->start = start;
        this->end = end;
        this->max = max;
        this->left = this->right = NULL;
    }
};

class Solution {
public:
    /**
     *@param A: a list of integer
     *@return: The root of Segment Tree
     */
    SegmentTreeNode * build(vector<int>& A) {
        if (A.size() == 0) {
            return NULL;
        } else {
            SegmentTreeNode *seg = new SegmentTreeNode(0, 0, 0);
            buildSeg(seg, A, 0, A.size() - 1);
            return seg;
        }
    }
    int buildSeg(SegmentTreeNode *seg, vector<int>& A, int left, int right);
};

int Solution::buildSeg(SegmentTreeNode *seg, vector<int>& A, int left, int right) {
    seg->start = left;
    seg->end = right;
    
    if (left == right) {
        seg->max = A[left];
        return A[left];
    } else {
        seg->left = new SegmentTreeNode(0, 0, 0);
        seg->left = new SegmentTreeNode(0, 0, 0);
        int left_max = buildSeg(seg->left, A, left, (left + right) / 2);
        int right_max = buildSeg(seg->right, A, (left + right) / 2 + 1, right);
        int MAX = max(left_max, right_max);
        seg->max = MAX;
        return MAX;
    }
}
int main() {
    vector<int> v;
    v.push_back(3);
    v.push_back(2);
    v.push_back(1);
    v.push_back(4);
    Solution s;
    s.build(v);

}
