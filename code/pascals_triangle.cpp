#include <iostream>
#include "data.h"
#include "util/readData.h"

using namespace std;

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		if (numRows == 0)
		  return {};
		if (numRows == 1)
		  return {{1}};
		vector<vector<int>> result = {{1}};
		for (int i=1; i<numRows; i++) {
			vector<int> r = {1};
			for (int j=1; j<i; j++){
				r.push_back(result[i-1][j-1] + result[i-1][j]);
			}
			r.push_back(1);
			result.push_back(r);
		}
		return result;
	}
};

int main(int argc, char **argv)
{
    Solution s;
	auto result = s.generate(5);
	for (auto r : result){
	  for (auto n : r)
		cout << n << " ";
	  cout << endl;
	}
    return 0;
}
