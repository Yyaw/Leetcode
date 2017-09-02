#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <unistd.h>
#include "data.h"

using namespace std;

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode> s;
        vector<int> result;
        bool flag = false; //左边是否遍历过了
        if (root == NULL)
            return result;
        TreeNode *tmp = root;
        do{
            if (tmp->left != NULL && !flag){
                s.push(*tmp);    
                tmp = tmp->left;
                continue;
            }
            result.insert(result.end(), tmp->val);
            if (tmp->right != NULL){
                tmp = tmp->right;
                flag = false;
            }else if(s.size() != 0){
                tmp = &s.top();
                flag = true;
                s.pop();
            }else{
                tmp = NULL;
            }
        }while (tmp != NULL);
        return result;
    }
};

int main(int argc, char **argv)
{
    TreeNode *root = NULL;
    for (int i=1; i<argc; i++){
        root = insert(root, atoi(argv[i]));
    }
    Solution s;
    vector<int> result = s.inorderTraversal(root);
    for(auto r : result)
        cout << r << " ";
    cout << endl;
    return 0;
}