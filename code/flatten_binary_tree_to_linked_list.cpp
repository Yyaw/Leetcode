#include <iostream>
#include "data.h"

using namespace std;

class Solution
{
  public:
    // void flatten(TreeNode *root)
    // {
    //     if (root == NULL || isLeaf(root))
    //         return;
    //     TreeNode *left = root->left;
    //     TreeNode *right = root->right;
    //     if (left)
    //         flatten(left);
    //     if (right)
    //         flatten(right);
    //     TreeNode *tmp = left;
    //     while (tmp && tmp->right != NULL)
    //         tmp = tmp->right;
    //     if (tmp)
    //     {
    //         tmp->right = right;
    //         root->right = left;
    //         root->left = NULL;
    //     }
    //     else
    //     {
    //         root->right = right;
    //     }
    // }

    void flatten(TreeNode *root)
    {
        TreeNode *now = root;
        while (now)
        {
            if (now->left)
            {
                TreeNode *tmp = now->left;
                while(tmp->right)
                    tmp  = tmp->right;
                tmp->right = now->right;
                now->right = now->left;
                now->left = NULL;
            }
            now = now->right;
        }
    }

    static inline bool isLeaf(TreeNode *root)
    {
        return root != NULL && root->left == NULL && root->right == NULL;
    }
};

int main(int argc, char **argv)
{
    Solution s;
    vector<int> v = {1, 2};
    TreeNode *root = createTreeByLevel(v);
    root->right = NULL;
    s.flatten(root);
    return 0;
}