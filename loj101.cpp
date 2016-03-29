#include <cstdio>

using namespace std;
bool isSymmetric(TreeNode* root) {
    if(root == NULL) return true;
    else isSymmetric(root->left, root->right);
}
bool isSymmetric(TreeNode* left, TreeNode* right){
    if(left == NULL && right == NULL) return true;
    if(left == NULL || right == NULL) return false;
    return left->val == right->val && isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
}
int main() {
    return 0;
}
