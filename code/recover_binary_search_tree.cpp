#include <iostream>
#include "data.h"

using namespace std;

class Solution
{
  public:
    void recoverTree(TreeNode *root)
    {
        TreeNode *pre = NULL, *tmp = NULL, *t1 = NULL, *t2 = NULL;
        while (root != NULL)
        {
            if (root->left == NULL)
            {
                if (pre != NULL && pre->val > root->val)
                    {
                        if (t1 == NULL)
                        {
                            t1 = pre;
                            t2 = root;
                        }
                        else
                            t2 = root;
                    }
                pre = root;
                root = root->right;
            }
            else
            {
                tmp = root->left;
                while (tmp->right != NULL && tmp->right != root)
                    tmp = tmp->right;
                if (tmp->right != NULL)
                {
                    if (pre != NULL && pre->val > root->val)
                    {
                        if (t1 == NULL)
                        {
                            t1 = pre;
                            t2 = root;
                        }
                        else
                            t2 = root;
                    }
                    pre = root;
                    tmp->right = NULL;
                    root = root->left;
                }
                else
                {
                    tmp->right = root;
                    root = root->right;
                }
            }
        }
        if (t1 != NULL && t2 != NULL)
        {
            int t = t1->val;
            t1->val = t2->val;
            t2->val = t;
        }
    }
};

int main(int argc, char **argv)
{
    TreeNode *root = new TreeNode(0);
    TreeNode *left = new TreeNode(1);
    root->left = left;
    Solution s;
    s.recoverTree(root);
    return 0;
}