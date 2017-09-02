#include <iostream>
#include <vector>
#include "data.h"

using namespace std;

class Solution
{
  public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        vector<vector<TreeNode *>> tmpResult;
        if (root == NULL)
            return result;
        int level = 0;
        int index = 0;
        tmpResult.push_back(vector<TreeNode *>());
        tmpResult[level].push_back(root);
        TreeNode *tmp;
        while (true)
        {
            tmp = tmpResult[level][index];
            if (tmp->left != NULL)
            {
                if (tmpResult.size() == level+1)
                    tmpResult.push_back(vector<TreeNode *>());
                tmpResult[level+1].push_back(tmp->left);
            }
            if (tmp->right != NULL)
            {
                if (tmpResult.size() == level+1)
                    tmpResult.push_back(vector<TreeNode *>());
                tmpResult[level+1].push_back(tmp->right);
            }
            index++;
            if (index == tmpResult[level].size())
            {
                index = 0;
                level++;
                if (level == tmpResult.size())
                    break;
            }
        }
        for (int i=0; i<tmpResult.size(); i++)
        {
            vector<int> t;
            for (int j=0; j<tmpResult[i].size(); j++)
            {
                t.push_back(tmpResult[i][j]->val);
            }
            result.push_back(t);
        }
        return result;
    }
};

int main(int argc, char **argv)
{
    TreeNode *root = new TreeNode(3);
    TreeNode *l1 = new TreeNode(9);
    TreeNode *r1 = new TreeNode(20);
    TreeNode *rl = new TreeNode(15);
    TreeNode *rr = new TreeNode(7);
    r1->left = rl;
    r1->right = rr;
    root->left = l1;
    root->right = r1;
    Solution s;
    s.levelOrder(root);
    return 0;
}