/*************************************************************************
 *  --------->    FILE: max-points-on-line.cpp
 *  --------->    AUTHOR: Aaron
 *  --------->    MAIL: chengfeizh@gmail.com
 *  --------->    DATE: 09/01/2015    TIME:20:22:35
 ************************************************************************/
#include <map>
#include <float.h>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
//typedef map<const char*, string, hash<const char*>, compare_str> StrIntMap;
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    /**
     * @param points an array of point
     * @return an integer
     */
    int maxPoints(vector<Point>& points) {
        // Write your code here
        if (points.size() == 0) {
            return 0;
        } else {
            int MAX = 1;
            for (int i = 0; i < points.size(); i++) {
                map<double, int> result;
                int one = 0;  // count the coinside points number
                double k = 0;
                int tmp_max = 1;
                for (int j = i + 1; j < points.size(); j++) {
                    if ((points[i].x == points[j].y) && (points[i].y == points[j].y)) {
                        one++;
                        continue;
                    } else if (points[i].x == points[j].x) { // perpendicular to the Y
                        k = DBL_MAX;
                    } else {
                        k = (points[i].y - points[j].y) * 1.0 / (points[i].x - points[j].x);

                    }
                    // didn't insert map so to insert
                    map <double, int>::iterator it;
                    it = result.find(k);
                    int n = 0;
                    if (it == result.end()) {
                        n = 2;
                        result[k] = n;
                    } else {
                        n = it->second + 1;
                        result[k] = n;
                    }
                    
                    tmp_max = max(tmp_max, n);
                }
                // and the coinside points
                MAX = max(MAX, tmp_max + one);
            }
            return MAX;
        }
        
    }
};

int main() {
    Solution s;
    vector<Point> p;
    p.push_back(Point(0, 9));
    p.push_back(Point(138, 429));
    p.push_back(Point(115, 359));
    p.push_back(Point(115, 359));
    p.push_back(Point(-30, -102));
    p.push_back(Point(230, 709));
    p.push_back(Point(-150, -686));
    p.push_back(Point(-135, -613));
    p.push_back(Point(-60, -248));
    p.push_back(Point(-161, -481));
    p.push_back(Point(207, 639));
    p.push_back(Point(23, 79));
    p.push_back(Point(-230, -691));
    p.push_back(Point(-115, -341));
    p.push_back(Point(92, 289));
    p.push_back(Point(60, 336));
    p.push_back(Point(-105, -467));
    p.push_back(Point(135, 701));
    p.push_back(Point(-90, -394));
    p.push_back(Point(-184, -551));
    p.push_back(Point(150, 774));
    cout << s.maxPoints(p) << endl;
    return 0;
}
