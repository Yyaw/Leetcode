#include <iostream>
#include "data.h"
#include "util/readData.h"
#include <assert.h>

using namespace std;

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        assert(preorder.size() == inorder.size());
        if (preorder.size() == 0)
        {
            return NULL;
        }
        TreeNode* node = new TreeNode(preorder[0]);
        if (preorder.size() == 1 && inorder.size() == 1)
        {
            return node;
        }
        int rootNum = preorder[0];
        vector<int>::iterator it;
        for (it = inorder.begin(); it != inorder.end(); ++it)
        {
            if (*it == rootNum)
            {
                break;
            }
        }
        vector<int> preLeft = vector<int>(preorder.begin(), preorder.begin() + (it-inorder.begin() - 1)), 
                    preRight = vector<int>(preorder.begin() + (it - inorder.begin() + 1), preorder.end()), 
                    inLeft = vector<int>(inorder.begin(), it - 1), 
                    inRight = vector<int>(it + 1, inorder.end());
        node->left = buildTree(preLeft, inLeft);
        node->right = buildTree(preRight, inRight);
        return node;
    }
};

int main(int argc, char **argv)
{
    Solution s;
    assert(argc > 1);
    char *file = argv[1];
    vector<vector<int>> data = ReadData::readIntVec(file);
    return 0;
}
