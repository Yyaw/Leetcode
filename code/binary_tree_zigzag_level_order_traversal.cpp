#include <iostream>
#include <vector>
#include <queue>
#include "data.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        vector<vector<int>> result;
        if (root == NULL)
            return result;
        queue<TreeNode *> nodeQueue;
        bool leftToright = true;
        nodeQueue.push(root);
        TreeNode *tmpNode;
        int index;
        while (!nodeQueue.empty())
        {
            int size = nodeQueue.size();
            vector<int> tmp(size);
            for (int i=0; i<size;i++)
            {
                tmpNode = nodeQueue.front();
                nodeQueue.pop();
                index = leftToright ? i : size - 1 - i;
                tmp[index] = tmpNode->val;
                if (tmpNode->left != NULL)
                    nodeQueue.push(tmpNode->left);
                if (tmpNode->right != NULL)
                    nodeQueue.push(tmpNode->right);
            }
            result.push_back(tmp);
            leftToright = !leftToright;
        }
        return result;
    }
};

int main(int argc, char **argv)
{
    Solution s;
    return 0;
}