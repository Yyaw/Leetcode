#include <iostream>
#include "data.h"
#include "util/readData.h"

using namespace std;

class Solution {
public:
   void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	   int index = m + n - 1;
	   m = m - 1;
	   n = n - 1;
	   while (m >= 0 && n >= 0) {
		   if (nums1[m] > nums2[n]) {
			   nums1[index--] = nums1[m--];
		   }else{
			   nums1[index--] = nums2[n--];
		   }
	   }
	   if (n >= 0){
		   while (n >= 0)
			 nums1[index--] = nums2[n--];
	   }
   }
};

int main(int argc, char **argv)
{
    Solution s;
	vector<vector<int>> data = readIntVector(argv[1]);
	vector<int> nums1 = data[0];
	vector<int> nums2 = data[1];
	int m = nums1.size();
	int n = nums2.size();
	nums1.reserve(nums1.size() + nums2.size());
	s.merge(nums1, m, nums2, n);
	for (int n : nums1)
	  cout << n << endl;
    return 0;
}
