#include <iostream>
#include "data.h"

using namespace std;

class Solution {
public:
    int sumNumbers(TreeNode *root) {
	int sum = 0;
	return sumNumbers(root, 0, sum);
    }
    void sumNumbers(TreeNode *root, int pre, int &sum) {
	if (root == NULL) 
	    return;
	if (root->left == NULL && root->right == NULL) {
	    sum += pre * 10 + root->val;
	    return;
	}
	if (root->left != NULL)
	   sumNumbers(root->left, pre * 10 + root->val, sum);
	if (root->right != NULL)
	   sumNumbers(root->right, pre * 10 + root->val, sum);
	    
    }   
};

int main(int argc, char **argv)
{
    Solution s;
    return 0;
}
