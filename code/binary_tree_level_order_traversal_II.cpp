#include <iostream>
#include <queue>
#include "data.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode *> q1, q2;
        q1.push(root);
        while (!q1.empty() || !q2.empty()) {
            vector<int> r;
            if (!q1.empty()) {
                while (!q1.empty()) {
                    r.push_back(q1.front()->val);
                    if (q1.front()->left != NULL) {
                        q2.push(q1.front()->left);
                    }
                    if (q1.front()->right != NULL) {
                        q2.push(q1.front()->right);
                    }
                    q1.pop();
                }
            }else {
                while (!q2.empty()) {
                    r.push_back(q2.front()->val);
                    if (q2.front()->left != NULL) {
                        q1.push(q2.front()->left);
                    }
                    if (q2.front()->right != NULL) {
                        q1.push(q2.front()->right);
                    }
                    q2.pop();
                }
            }
            result.push_back(r);
        }
        return vector<vector<int>>(result.rbegin(), result.rend());
    }   
};

int main(int argc, char **argv)
{
    Solution s;
    return 0;
}





