#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void insertNode(TreeNode* &root, int val) {
    TreeNode* q = root;
    TreeNode* p = NULL;
    while(q != NULL) {
        p = q;
        if(p->val > val) {
            q = q->left;
        }else{
            q = q->right;
        }
    }
    if(p == NULL) {
        root = new TreeNode(val);
    }else if(p->val > val){
        p->left = new TreeNode(val);
    }else{
        p->right = new TreeNode(val);
    }
}

void Traverse(TreeNode* root) {
    if(root != NULL) {
        printf("%d\n", root->val);
        Traverse(root->left);
        Traverse(root->right);
    }
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    if(root == NULL) return ans;
    stack<TreeNode*> s;
    TreeNode* p = root;
    while(!s.empty() || p != NULL) {
        if(p != NULL) {
            s.push(p);
            p = p->left;
        }else{
            p = s.top();
            s.pop();
            ans.push_back(p->val);
            p = p->right;
        }
    }
    return ans;
}

int main() {
    TreeNode* root = NULL;
    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 3);

    cout << "bingo" << endl;

    Traverse(root);

    vector<int> ans = inorderTraversal(root);

    for(int i = 0; i < (int)ans.size(); i ++)
        cout << ans[i] << " ";
    cout << endl;

    return 0;
}
