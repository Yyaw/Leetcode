#include <iostream>
#include "data.h"

using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
		if (s1.length() != s2.length())
            return false;
        if (s1 == s2)
            return true;
        int length = s1.length();
        bool dp[length][length][length] = {false,};
        for (int i=0; i<length; i++)
            for (int j=0; j<length; j++)
                dp[i][j][1] = s1[i] == s2[j];
        for (int len=2; len <=length; len++) {
            for (int i=0; i<=length-len; i++) {
                for (int j=0; j<=length-len; j++) {
                    for (int k=1; k<len; k++) {
                        if (dp[i][j][k] && dp[i+k][j+k][len-k] || dp[i+k][j][len-k] && dp[i][j+len-k][k])
                            dp[i][j][len] = true;
                    }
                }
            }
        }
        return dp[0][0][length];
    }
};

int main(int argc, char **argv)
{
    Solution s;
    string s1(argv[1]);
    string s2(argv[2]);
    cout << s.isScramble(s1, s2) << endl;
    return 0;
}