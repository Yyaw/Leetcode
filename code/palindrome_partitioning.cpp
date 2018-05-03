#include <iostream>
#include "data.h"
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<string> > partition(string s) {
		vector<vector<string> > result;
		if (s.empty())
			return result;
		vector<string> path;
		dfs(0, s, path, result);
		return result;
	}

	void dfs(int index, string s, vector<string>& path, vector<vector<string> >& result) {
		if (index == s.size()) {
			result.push_back(path);
			return;
		}
		for (int i=index; i<s.size(); i++) {
			if (isPalindrome(s, index, i) {
					path.push_back(s.substr(index, i-index+1));
					dfs(i+1, s, path, ret);
					path.pop_back();
			}
		}
	}

	bool isPalindrome(string s, int begin, int end) {
		if (end > s.size())
			return false;
		while (end > begin) {
			if (s[end--] != s[begin++])
				return false;
		}
		return true;
	}
};

int main(int argc, char **argv)
{
    Solution s;
    return 0;
}
