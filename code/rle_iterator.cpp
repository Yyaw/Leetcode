#include <iostream>
#include <cassert>
#include "data.h"
#include "util/readData.h"

using namespace std;

class RLEIterator {
    vector<int> vec;
public:
    RLEIterator(vector<int> A) {
        assert(A.size() % 2 == 0);
        vec = A; 
    }
    
    int next(int n) {
        if (vec.size() == 0)
        {
            return -1;
        }
        int num = vec[0];
        if (num >= n)
        {
            vec[0] -= n;
            return vec[1];
        }
        else
        {
            n -= num;
            vec.erase(vec.begin());
            vec.erase(vec.begin());
            return next(n);
        }
        return -1;
    }
};

class Solution {
public:
    
};

int main(int argc, char **argv)
{
    Solution s;
    vector<vector<int>> data = ReadData::readIntVec(argv[1]);
    assert(data.size() == 2);
    vector<int> rle = data[0];
    vector<int> next = data[1];
    RLEIterator rleIterator(rle);
    for (auto i : next)
    {
        cout << "--------------------" << endl;
        cout << rleIterator.next(i) << endl;
    }
    return 0;
}
