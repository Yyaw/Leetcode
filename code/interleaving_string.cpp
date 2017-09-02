#include <iostream>
#include <queue>
#include "data.h"

using namespace std;

class Solution
{
  public:
    // bool isInterleave(string s1, string s2, string s3)
    // {
    //     if (s1.size() + s2.size() != s3.size())
    //         return false;
    //     return isInterleave(s1, 0, s2, 0, s3, 0);
    // }

    // bool isInterleave(string s1, int index1, string s2, int index2, string s3, int index3)
    // {
    //     if (index1 == s1.size())
    //     {
    //         for (int i = index2, j = index3; i < s2.size(); i++, j++)
    //             if (s2[i] != s3[j])
    //                 return false;
    //         return true;
    //     }
    //     if (index2 == s2.size())
    //     {
    //         for (int i = index1, j = index3; i < s1.size(); i++, j++)
    //             if (s1[i] != s3[j])
    //                 return false;
    //         return true;
    //     }
    //     if (s1[index1] != s3[index3] && s2[index2] != s3[index3])
    //         return false;
    //     if (s1[index1] == s3[index3])
    //     {
    //         if (isInterleave(s1, index1+1, s2, index2, s3, index3+1))
    //         {
    //             return true;
    //         }else{
    //             if (s2[index2] == s3[index3])
    //                 return isInterleave(s1, index1, s2, index2+1, s3, index3+1);
    //             return false;
    //         }
    //     }else{
    //         return isInterleave(s1, index1, s2, index2+1, s3, index3+1);
    //     }
    // }

    // struct point
    // {
    //     int x;
    //     int y;
    //     bool operator ==(const point &p)
    //     {
    //         return p.x == x && p.y == y;
    //     }
    // };

    bool isInterleave(string s1, string s2, string s3)
    {
        int size1 = s1.size();
        int size2 = s2.size();
        bool **dp = new bool* [size1+1];
        for (int i=0; i<=size1; i++)
            dp[i] = new bool[size2+1]{false};
        dp[0][0] = true;
        for (int i=1; i<=size1; i++)
        {
            dp[i][0] = (s1[i-1] == s3[i-1]) && dp[i-1][0];
        }
        for (int i=1; i<=size2; i++)
        {
            dp[0][i] = (s2[i-1] == s3[i-1]) && dp[0][i-1];
        }
        for (int i=1; i<=size1; i++)
        {
            for (int j=1; j<=size2; j++)
            {
                if (s1[i - 1] == s3[i+j-1] && dp[i-1][j])
                    dp[i][j] = true;
                if (s2[j - 1] == s3[i+j-1] && dp[i][j-1])
                    dp[i][j] = true;
            }
        }
        return dp[size1][size2];
    }
};

int main(int argc, char **argv)
{
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    Solution solution;
    bool b = solution.isInterleave(s1, s2, s3);
    cout << b << endl;
    return 0;
}