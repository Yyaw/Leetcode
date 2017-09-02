#include <iostream>
#include "data.h"

using namespace std;

ListNode *node = NULL;

class Solution
{
  public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        ListNode *tmp = head;
        node = head;
        int size = 0;
        while (tmp != NULL)
        {
            tmp = tmp->next;
            size++;
        }
        return createTree(0, size-1);
    }
    TreeNode *createTree(int begin, int end)
    {
        if (begin > end)
            return NULL;
        int mid = begin + (end - begin) / 2;
        TreeNode *left = createTree(begin, mid - 1);
        TreeNode *tNode = new TreeNode(node->val);
        node = node->next;
        TreeNode *right = createTree(mid + 1, end);
        tNode->left = left;
        tNode->right = right;
        return tNode;
    }
};

int main(int argc, char **argv)
{
    Solution s;
    return 0;
}