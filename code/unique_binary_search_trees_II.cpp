#include <iostream>
#include "data.h"

using namespace std;

class Solution
{
  public:
    vector<TreeNode *> generateTrees(int n)
    {
        if (n == 0)
        {
            return vector<TreeNode*>();
        }
        return generateTrees(1, n);
    }

    vector<TreeNode *> generateTrees(int left, int right)
    {
        vector<TreeNode*> result;
        if (left == right)
        {
            TreeNode *node = new TreeNode(left);
            result.push_back(node);
            return result;
        }
        if (left > right)
        {
            result.push_back(NULL);
            return result;
        }
        for (int i = left; i <= right; i++)
        {
            vector<TreeNode*> leftNodes = generateTrees(left, i-1);
            vector<TreeNode*> rightNodes = generateTrees(i+1, right);
            for (auto leftNode : leftNodes)
            {
                for (auto rightNode : rightNodes)
                {
                    TreeNode *node = new TreeNode(i);
                    node->left = leftNode;
                    node->right = rightNode;
                    result.push_back(node);
                }
            }
        }
        return result;
    }
};

int main(int argc, char **argv)
{
    Solution s;
    cout << s.generateTrees(3).size() << endl;
    return 0;
}