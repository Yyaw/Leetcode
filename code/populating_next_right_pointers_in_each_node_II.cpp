#include <iostream>
#include "data.h"

using namespace std;

class Solution
{
  public:
    void connect(TreeLinkNode *root)
    {
        if (root == NULL)
            return;
        TreeLinkNode *level = root;
        while (level != NULL)
        {
            TreeLinkNode *cur = level;
            TreeLinkNode *tail = NULL;
            while (cur != NULL)
            {
                if (cur->left != NULL)
                {
                    if (tail == NULL)
                        tail = cur->left;
                    else{
                        tail->next = cur->left;
                        tail = tail->next;
                    }
                }
                if (cur->right != NULL)
                {
                    if (tail == NULL)
                        tail = cur->right;
                    else {
                        tail->next = cur->right;
                        tail = tail->next;
                    }
                }
                cur = cur->next;
            }
            while (level != NULL && (level->left == NULL && level->right == NULL))
                level = level->next;
            if (level == NULL)
                continue;
            if (level->left != NULL)
                level = level->left;
            else
                level = level->right;
        }
    }
};

int main(int argc, char **argv)
{
    Solution s;
    TreeLinkNode *root = new TreeLinkNode(1);
    TreeLinkNode *l = new TreeLinkNode(2);
    TreeLinkNode *r = new TreeLinkNode(3);
    root->left = l;
    root->right = r;
    TreeLinkNode *ll = new TreeLinkNode(4);
    TreeLinkNode *lr = new TreeLinkNode(5);
    l->left = ll;
    l->right = lr;
    s.connect(root);
    return 0;
}