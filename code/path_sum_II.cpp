#include <iostream>
#include <vector>
#include <stack>
#include "data.h"

using namespace std;

class Solution
{
  public:
    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        vector<vector<int>> result;
        vector<int> tmp;
        stack<TreeNode *> node_stack;
        if (root == NULL)
            return result;
        node_stack.push(root);
        tmp.push_back(root->val);
        int now_sum = root->val;
        TreeNode *tail = root;
        while (!node_stack.empty())
        {
            if (isLeaf(tail)) //回退
            {
                if (now_sum == sum)
                    result.push_back(tmp);
                if (tail == root)
                    return result;
                node_stack.pop();
                tmp.pop_back();
                TreeNode *p = node_stack.top();
                node_stack.pop();
                tmp.pop_back();
                now_sum -= p->val;
                now_sum -= tail->val;
                while ((p->right == NULL || isRightChild(p, tail)) && !node_stack.empty())
                {
                    tail = p;
                    p = node_stack.top();
                    node_stack.pop();
                    tmp.pop_back();
                    now_sum -= p->val;
                }
                if (node_stack.empty() && isRightChild(p, tail))
                    continue;
                else
                {
                    node_stack.push(p);
                    now_sum += p->val;
                    tmp.push_back(p->val);
                    tail = p->right;
                    node_stack.push(tail);
                    now_sum += tail->val;
                    tmp.push_back(tail->val);
                }
            }
            else
            {
                if (now_sum >= sum) //回退
                {
                    if (tail == root)
                        return result;
                    node_stack.pop();
                    tmp.pop_back();
                    TreeNode *p = node_stack.top();
                    node_stack.pop();
                    tmp.pop_back();
                    now_sum -= p->val;
                    now_sum -= tail->val;
                    while ((p->right == NULL || isRightChild(p, tail)) && !node_stack.empty())
                    {
                        tail = p;
                        p = node_stack.top();
                        node_stack.pop();
                        tmp.pop_back();
                        now_sum -= p->val;
                    }
                    if (node_stack.empty() && isRightChild(p, tail))
                        continue;
                    else
                    {
                        node_stack.push(p);
                        now_sum += p->val;
                        tmp.push_back(p->val);
                        tail = p->right;
                        node_stack.push(tail);
                        now_sum += tail->val;
                        tmp.push_back(tail->val);
                    }
                }
                else //继续往下
                {
                    if (tail->left != NULL)
                    {
                        tail = tail->left;
                    }
                    else
                    {
                        tail = tail->right;
                    }
                    node_stack.push(tail);
                    tmp.push_back(tail->val);
                    now_sum += tail->val;
                }
            }
        }
        return result;
    }

    static inline bool isLeaf(TreeNode *node)
    {
        return node->left == NULL && node->right == NULL;
    }

    static inline bool isRightChild(TreeNode *n1, TreeNode *n2)
    {
        return n1 == NULL ? false : n1->right == n2;
    }

    static inline bool isLeftChild(TreeNode *n1, TreeNode *n2)
    {
        return n1 == NULL ? false : n1->left == n2;
    }
};

int main(int argc, char **argv)
{
    Solution s;
    vector<int> v = {-2, -1, -3};
    TreeNode *root = createTreeByLevel(v);
    vector<vector<int>> result = s.pathSum(root, -5);
    for (auto r : result)
    {
        for (auto n : r)
            cout << n << " ";
        cout << endl;
    }
    return 0;
}