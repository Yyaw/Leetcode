#include <iostream>
#include <vector>
#include "data.h"

using namespace std;

class Solution
{
  public:
    vector<string> result;
    for (int i = index + 1; i <= index + 3; i++)
    {
        if (s.size() - i > (num - 1) * 3)
            continue;
        else if ((i == index + 3 && s[index] > '2') || (i > index + 1 && s[index] == '0') || (i == index + 3 && s[index] == '2' && s[index+1] > '5') || (i == index+2 && s[index] == '2' && s[index+1] == '5' && s[index+2] > '5'))
            return result;
        else
        {
            s.insert(i, ".");
            if (num - 1 > 1)
            {
                vector<string> tmp = restoreIpAddresses(s, num - 1, i + 1);
                result.insert(result.end(), tmp.cbegin(), tmp.cend());
            }
            else
            {
                switch (s.size() - i)
                {
                case 2:
                    result.insert(result.end(), s);
                    break;
                case 3:
                    if (s[i + 1] != '0')
                        result.insert(result.end(), s);
                    break;
                case 4:
                    if (s[i + 1] > '0' && s[i + 1] < '2')
                        result.insert(result.end(), s);
                    else if (s[i + 1] == '2' && s[i + 2] >= '0' && s[i + 2] < '5')
                        result.insert(result.end(), s);
                    else if (s[i + 2] == '5' && s[i + 3] >= '0' && s[i + 3] <= '5')
                        result.insert(result.end(), s);
                    break;
                default:
                    break;
                }
            }
            s.erase(s.cbegin() + i);
        }
    }
    return result;
};

int main(int argc, char **argv)
{
    Solution s;
    vector<string> result = s.restoreIpAddresses(argv[1]);
    for (auto r : result)
        cout << r.c_str() << endl;
    return 0;
}