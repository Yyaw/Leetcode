#include <iostream>
#include <algorithm>
#include "data.h"

using namespace std;

class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() == 0)
            return 0;
        int states[2][4] = {INT32_MIN, 0, INT32_MIN, 0}, cur = 0, next = 1;
        for (int i = 0; i < prices.size(); i++)
        {
            states[next][0] = max(states[cur][0], -prices[i]);
            states[next][1] = max(states[cur][1], states[cur][0] + prices[i]);
            states[next][2] = max(states[cur][2], states[cur][1] - prices[i]);
            states[next][3] = max(states[cur][3], states[cur][2] + prices[i]);
            swap(cur, next);
        }
        return max(states[cur][1], states[cur][3]);
    }
    int maxProfit(vector<int> &prices)
    {
        
    }
};

int main(int argc, char **argv)
{
    Solution s;
    return 0;
}