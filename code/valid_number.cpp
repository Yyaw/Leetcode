#include <iostream>
#include "data.h"

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        const char *str = s.c_str();
        bool dot = false;
        bool e = false;
        bool blank = false;
        while (*str == ' ')
            ++str;
        while (*str != '\0') {
            if (*str == 'e') {
                if (e || blank)
                    return false;
                e = true;
            }
            else if (*str == ' ') 
                blank = true;
            else if (*str == '.') {
                if (dot || blank)
                    return false;
                dot = true;
            }
            else if (*str >= '0' || *str <= '9') {
                if (blank) {
                    return false;
                }
            }else {
                return false;
            }
        }
    }
};

int main(int argc, char **argv)
{
    Solution s;
    return 0;
}