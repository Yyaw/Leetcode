#include <string>
#include <iostream>
#include "data.h"

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t)
    {
        int s_size = s.size();
        int t_size = t.size();
        int **dp = new int*[t_size + 1];
        for (int i=0; i<=t_size; i++)
            dp[i] = new int[s_size+1];
        for (int i=0; i<=s_size; i++)
            dp[0][i] = 1;
        for (int i=1; i<=t_size; i++)
            dp[i][0] = 0;
        for (int i=1; i<=t_size; i++)
        {
            for(int j=1; j<=s_size; j++)
            {
                dp[i][j] = dp[i][j-1];
                if (s[j-1] == t[i-1])
                {
                    dp[i][j] += dp[i-1][j-1];
                }
            }
        }
        return dp[t_size][s_size];
    }
    
};

int main(int argc, char **argv)
{
    Solution s;
    string ss, t;
    cin >> ss >> t;
    cout << s.numDistinct(ss, t) << endl;
    return 0;
}