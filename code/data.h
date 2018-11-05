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

TreeNode *insert(TreeNode *root, int val)
{
    TreeNode *pnode = root;
    if (root == 0)
    {
        root = new TreeNode(val);
        return root;
    }
    while (1)
    {
        if (val == pnode->val)
            break;
        if (val > pnode->val && pnode->right != 0)
            pnode = pnode->right;
        else
        {
            TreeNode *node = new TreeNode(val);
            pnode->right = node;
            break;
        }
        if (val < pnode->val && pnode->left != 0)
            pnode = pnode->left;
        else
        {
            TreeNode *node = new TreeNode(val);
            pnode->left = node;
            break;
        }
    }
    return root;
}

TreeNode *createTreeByLevel(std::vector<int> array)
{
    if (array.size() == 0)
        return 0;
    int index = 1;
    std::queue<TreeNode *> queue;
    TreeNode *root = new TreeNode(array[0]);
    queue.push(root);
    while (index < array.size())
    {
        TreeNode *left = 0, *right = 0;
        if (array[index++] != -1)
            left = new TreeNode(array[index - 1]);
        if (array[index++] != -1)
            right = new TreeNode(array[index - 1]);
        TreeNode *p = queue.front();
        queue.pop();
        queue.push(left);
        queue.push(right);
        if (p == 0 && (left != 0 || right != 0))
            throw 1;
        if (p != 0)
            p->left = left, p->right = right;
    }
    return root;
}

std::vector<int> inorder(TreeNode *root)
{
    std::vector<int> result;
    if (root == 0)
        return result;
    if (root->left != 0)
    {
        std::vector<int> tmp = inorder(root->left);
        result.insert(result.end(), tmp.cbegin(), tmp.cend());
    }
    result.insert(result.end(), root->val);
    if (root->right != 0)
    {
        std::vector<int> tmp = inorder(root->right);
        result.insert(result.end(), tmp.cbegin(), tmp.cend());
    }
}

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
