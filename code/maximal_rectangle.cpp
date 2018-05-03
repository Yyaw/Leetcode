#include <iostream>
#include <vector>
#include "util/readData.h"
#include "data.h"

using namespace std;

class Solution {
public:

    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> heights(matrix[0].size());
        for (int i=0; i<matrix[0].size(); i++) {
            heights[i] = matrix[0][i] - '0';
        }
        int max = largestRectangleArea(heights);
        int tmp_max = 0;
        for (int i=1; i<matrix.size(); i++) {
            for (int j=0; j<matrix[i].size(); j++) {
                if (matrix[i][j] == '0')
                    heights[j] = 0;
                else
                    ++heights[j];
            }
            tmp_max = largestRectangleArea(heights);
            if (tmp_max > max)
                max = tmp_max;
        }      
        return max;
    }

    int largestRectangleArea(vector<int> height) {
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
    vector<vector<char>> data = readCharVector(argv[1]);
    cout << s.maximalRectangle(data) << endl;
    return 0;
}