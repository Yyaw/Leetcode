#ifndef _LEETCODE_DATA_H_
#define _LEETCODE_DATA_H_
#include <vector>
#include <queue>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(0) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(0), right(0) {}
};

struct TreeLinkNode
{
    int val;
    TreeLinkNode *left;
    TreeLinkNode *right;
    TreeLinkNode *next;
    TreeLinkNode(int x) : val(x), left(0), right(0), next(0) {}
};

TreeNode *insert(TreeNode *root, int val);

TreeNode *createTreeByLevel(std::vector<int> array);

std::vector<int> inorder(TreeNode *root);

struct RandomListNode
{
  int label;
  RandomListNode *next, *random;
  RandomListNode(int x):label(x),next(NULL),random(NULL){}
};

//不适合所有移除操作
// TreeNode *remove(TreeNode *root, int val)
// {
//     TreeNode *pnode = root;
//     TreeNode *parent = pnode;
//     while (1)
//     {
//         if (val > root->val)
//         {
//             pnode = pnode->right;
//             parent = pnode;
//         }else if (val < root->val){
//             pnode = pnode->left;
//             parent = pnode;
//         }else{
//             if (pnode == parent->left)
//                 parent->left = 0;
//             else
//                 parent->right = 0;
//         }
//     }
//     return root;
// }


#endif