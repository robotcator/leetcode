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

void FindKth(TreeNode* root, int& k, int& ans) {
    if(root) {
        FindKth(root->left, k, ans);
        k --;
        if(k == 0) {
            ans = root->val;
            return ;
        }
        FindKth(root->right, k, ans);
    }
}

int kthSmallest(TreeNode* root, int k) {
    int ans = 0;
    FindKth(root, k, ans);
    cout << k << endl;
    return ans;
}

void Insert(TreeNode* &root, int key) {
    if(root == NULL) {
        root = new TreeNode(key);
    }else{
        if(key < root->val) Insert(root->left, key);
        else Insert(root->right, key);
    }
}

void Print(TreeNode* root) {
    if(root) {
        Print(root->left);
        printf("%d\n", root->val);
        Print(root->right);
    }
}

int main() {
    TreeNode* root = NULL;
    Insert(root, 5);
    Insert(root, 3);
    Insert(root, 4);
    Insert(root, 6);
    Insert(root, 2);
    cout << kthSmallest(root, 1) << endl;
    cout << kthSmallest(root, 2) << endl;
    cout << kthSmallest(root, 3) << endl;
    cout << kthSmallest(root, 5) << endl;

    return 0;
}
