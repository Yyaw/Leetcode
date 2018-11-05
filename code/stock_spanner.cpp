#include <iostream>
#include "data.h"
#include "util/readData.h"
#include <cassert>

using namespace std;

class StockSpanner {
public:
    vector<int> result;
    vector<int> prices;

    StockSpanner() {
        
    }
    
    int next(int price) {
        int i = result.size() - 1;
        if (i < 0)
        {
            result.push_back(1);
            prices.push_back(price);
            return 1;
        }
        if (price < prices[i])
        {
            result.push_back(1);
            prices.push_back(price);
            return 1;
        }
        int r = 1;
        while (i >= 0)
        {
            if (price >= prices[i])
            {
                r += result[i];
                i -= result[i];
            }
            else
            {
                result.push_back(r);
                prices.push_back(price);
                return r;
            }
        }
        result.push_back(r);
        prices.push_back(price);
        return r;
    }
};

class Solution {
public:
    
};

int main(int argc, char **argv)
{
    StockSpanner s;
    assert(argc == 2);
    vector<int> data = ReadData::readIntVec(argv[1])[0];
    for (auto d : data)
    {
        cout << s.next(d) << endl;
    }
    return 0;
}
