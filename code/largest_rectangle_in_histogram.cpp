#include <iostream>
#include <vector>
#include <stack>
#include "data.h"
#include "util/readData.h"

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int max = 0;
        height.push_back(0);
        vector<int> index;
        for (int i=0; i<height.size(); i++) {
            while (index.size() > 0 && height[index.back()] >= height[i]) {
                int h = height[index.back()];
                index.pop_back();
                int leight = index.size() > 0 ? index.back() : -1;
                if (h * (i - leight - 1) > max)
                    max = h * (i - leight - 1);
            }
            index.push_back(i);
        }
        return max;
    }
};

int main(int argc, char **argv)
{
    Solution s;
    vector<int> data = readIntVector(argv[1])[0];
    cout << s.largestRectangleArea(data) << endl;
    return 0;
}