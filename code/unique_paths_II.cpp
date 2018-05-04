#include <iostream>
#include <vector>
#include "data.h"

using namespace std;

class Solution {
public:
    //My solution
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) { //with dp
        int row = obstacleGrid.size();
        if (row <= 0) {
            return 0;
        }
        int col = obstacleGrid[0].size();
        if (col <= 0) {
            return 0;
        }
        vector<vector<int>> dp(row, vector<int>(col, 1));
        if (obstacleGrid[0][0] == 1) {
            return 0;
        }
        for (int i=1; i<row; i++) {
            if (obstacleGrid[i][0] == 1) {
                for (int j=i; j<row; j++) {
                    dp[j][0] = 0;
                }
                break;
            }
        }
        for (int i=1; i<col; i++) {
            if (obstacleGrid[0][i] == 1) {
                for (int j=i; j<col; j++) {
                    dp[0][j] = 0;
                }
                break;
            }
        }
        for (int i=1; i<row; i++) {
            for (int j=1; j<col; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[row-1][col-1];
    }    

    //Other leetcoder's solution(very simple)
    int uniquePathsWithObstacles2(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        vector<vector<int>> dp(row+1, vector<int>(col+1, 0));
        dp[0][1] = 1;
        for (int i=1; i<=row; i++) {
            for (int j=1; j<=col; j++) {
                if (!obstacleGrid[i-1][j-1]) 
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[row][col];
    }

};

int main(int argc, char **argv)
{
    Solution s;
    vector<vector<int>> data = {{0,0,0}, {0,1,0}, {0,0,0}};
    int result = s.uniquePathsWithObstacles(data);
    cout << result << endl;
    return 0;
}