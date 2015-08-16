#include <cstdio>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* invertTree(TreeNode* root) {
   if(root) {
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);
        if(left != NULL || right != NULL) {
            root->left = right;
            root->right = left;
        }
   }
   return root;
}

int main() {
    return 0;
}
