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
    TreeNode *root = NULL;

}

void print(TreeNode* node) {
    if(node != NULL){
        print(node->left);
        print(node->right);
        printf("%d\n", node->val);
    }
}


/*
 *    5
 *  9   67
 *    37
 *  pre: 5, 9, 67, 37
 *  in: 9, 32, 67, 5
 *  post: 9, 37, 67, 5
 * */
int main() {
    vector<int> p, i;
    p.push_back(5);
    p.push_back(9);
    p.push_back(67);
    p.push_back(37);

    i.push_back(9);
    i.push_back(32);
    i.push_back(67);
    i.push_back(5);

    TreeNode* root = buildTree(p, i);

    print(root);

    return 0;
}
