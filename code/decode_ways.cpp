#include <iostream>

using namespace std;

class Solution
{
  public:
    int numDecodings(string s)
    {
        if (s.size() == 0)
            return 0;
        if (s[0] == '0')
            return 0;
        int a, b, tmp;
        a = 1;
        b = 1;
        for (int i=1; i<s.size(); i++)
        {
            if (s[i] == '0') {
                if (s[i-1] != '1' && s[i-1] != '2')
                    return 0;
                else
                    tmp = a;
            }
            else if (i<s.size() && s[i+1] != '0' && s[i-1] == '1')
                tmp = a+b;
            else if (i<s.size() && s[i+1] != '0' && s[i-1] == '2' && (s[i] < '7' && s[i] >= '0'))
                tmp = a+b;
            else 
                tmp = a;
            b = a;
            a = tmp;
        }
        return a;
    }
};

int main(int argc, char **argv)
{
    Solution s;
    cout << s.numDecodings(argv[1]) << endl;
    return 0;
}