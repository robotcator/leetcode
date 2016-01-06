#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

}

int main() {
    cout << "hello world" << endl;
    return 0;
}
