#include <iostream>
#include "data.h"

using namespace std;

int main(int argc, char **argv)
{
    vector<int> t = {5,4,8,11,-1,13,4,7,2,-1,-1,5,1};
    TreeNode *root = createTreeByLevel(t);
    vector<int> result =  inorder(root);
    for (auto r: result)
        cout << r << " ";
    cout << endl;
    return 0;
}