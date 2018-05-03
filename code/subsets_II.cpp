#include <iostream>
#include "data.h"
#include "util/readData.h"

using namespace std;

class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		if (nums.size() == 0)
		  return {};
		sort(nums.begin(), nums.end());
		vector<vector<int>> result(1);
		int last = nums[0], index = 1;
		int newIndex = 0;
		for (int i=0; i<nums.size(); i++) {
			if (nums[i] != last) {
				last = nums[i];
				index = result.size();
			}
			newIndex = result.size();
			for (int j=newIndex-index; j<newIndex; j++) {
				result.push_back(result[j]);
				result.back().push_back(nums[i]);
			}
		}
		return result;
	}
};

int main(int argc, char **argv)
{
    Solution s;
	vector<int> data = readIntVector(argv[1])[0];
	vector<vector<int>> result = s.subsetsWithDup(data);
	for (auto r:result) {
		for (auto num:r) {
			cout << num << " ";
		}
		cout << endl;
	}
    return 0;
}
