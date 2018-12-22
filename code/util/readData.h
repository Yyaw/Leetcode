#ifndef _LEETCODE_READ_DATA_H_
#define _LEETCODE_READ_DATA_H_

#include <vector>
#include <fstream>

class ReadData
{
public:
    static std::vector<std::vector<int>> readIntVec(char *file)
    {
        std::ifstream in(file, std::ios::in);
        std::vector<std::vector<int>> result;
        if (in.is_open())
        {
            while (!in.eof())
            {
                int num, n;
                in >> num;
                std::vector<int> vec;
                while (num-- > 0)
                {
                    in >> n;
                    vec.push_back(n);
                }
                result.push_back(vec);
            }
        }
        return result;
    }
};

#endif