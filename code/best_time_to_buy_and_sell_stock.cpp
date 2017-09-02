#include <iostream>
#include <vector>
#include <algorithm>
#include "data.h"

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int minprice = prices[0];
        int maxpro = 0;
        for (int i=0; i<prices.size(); i++)
        {
            minprice = min(prices[i], minprice);
            maxpro = max(maxpro, prices[i] - minprice);
        }
        return maxpro;
    }
};

int main(int argc, char **argv)
{
    Solution s;
    vector<int> v = {7,1,5,3,6,4};
    cout << s.maxProfit(v) << endl;
    return 0;
}