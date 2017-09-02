#include <iostream>
#include "data.h"

using namespace std;

/**
Note:
You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
*/
class Solution
{
  public:
    void connect(TreeLinkNode *root)
    {
        TreeLinkNode *level_tree = root;
        while (level_tree != NULL)
        {
            TreeLinkNode *cur = level_tree;
            while (cur != NULL)
            {
                if (cur->left != NULL)
                    cur->left->next = cur->right;
                if (cur->right != NULL && cur->next != NULL)
                    cur->right->next = cur->next->left;
                cur = cur->next;
            }
            level_tree = level_tree->left;
        }
    }
};

int main(int argc, char **argv)
{
    Solution s;
    return 0;
}