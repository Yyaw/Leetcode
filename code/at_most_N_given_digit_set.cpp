#include <iostream>
#include "data.h"
#include "util/readData.h"

using namespace std;

int getLengthOfN(int N)
{
    int length = 0;
    if (N < 0)
    {
        N = -N;
    }
    while (N > 0)
    {
        length += 1;
        N /= 10;
    }
    return length;
}

class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& D, int N) {
        
    }
};

int main(int argc, char **argv)
{
    Solution s;
    return 0;
}
