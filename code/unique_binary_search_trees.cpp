#include <iostream>
#include <stdlib.h>
#include "data.h"

using namespace std;

class Solution
{
  public:
    TreeNode* clone(TreeNode *root)
    {
        if (root == NULL)
            return NULL;
        TreeNode *node = new TreeNode(root->val);
        node->left = clone(root->left);
        node->right = clone(root->right);
        return node;
    }

    vector<TreeNode *> generateTrees(int n)
    {
        vector<TreeNode *> result;
        if (n==0)
            return result;
        TreeNode *first = new TreeNode(1);
        result.push_back(first);
        for (int i=2; i<=n; i++){
            for (int j=0; j<result.size(); j++)
            {
                TreeNode *root = result[j];
                TreeNode *tmp = clone(root);
                TreeNode *newroot = new TreeNode(i);
                newroot->left = newroot;
                result.push_back(newroot);
                result[j] = insert(root, i);
            }
        }
        return result;
    }
};

int main(int argc, char **argv)
{
    Solution s;
    vector<TreeNode *> tree = s.generateTrees(3);
    return 0;
}