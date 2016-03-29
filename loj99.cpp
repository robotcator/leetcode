#include <iostream>
#include <string>
#include <cstdio>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void insertNode(TreeNode * &root, int val) {
    if(root == NULL) root = new TreeNode(val);
    else{
        TreeNode* p = root;
        TreeNode* q = NULL;
        while(p != NULL) {
            if(root->val < val) {
                q = p;
                p = p->right;
            }else{
                q = p;
                p = p->left;
            }
        }
        if(q->val < val) q->right = new TreeNode(val);
        else q->left = new TreeNode(val);
    }
}

void print(TreeNode* root) {
    if(root != NULL) {
        printf("%d\n", root->val);
        print(root->left);
        print(root->right);
    }
}

void Travese(TreeNode* root, vector<TreeNode*> &v) {
    if(root != NULL) {
        Travese(root->left, v);
        v.push_back(root);
        Travese(root->right, v);
    }
}

void recoverTree(TreeNode* &root) {
    vector<TreeNode*> v;
    Travese(root, v);
    TreeNode* p1, *p2;
    vector<TreeNode*>::iterator it;
    for (it = v.begin()+1; it != v.end(); it ++) {
        if((*(it-1))->val > (*it)->val) {
            p1 = *(it-1);
            break;
        }
    }

    vector<TreeNode*>::reverse_iterator rit;
    for (rit = v.rbegin()+1; rit != v.rend(); rit ++) {
        if((*(rit-1))->val < (*rit)->val) {
            p2 = *(rit-1);
            break;
        }
    }

    int temp = p1->val;
    p1->val = p2->val;
    p2->val = temp;
}

int main() {
    TreeNode *root = NULL;
    insertNode(root, 2);
    insertNode(root, 1);
    insertNode(root, 3);
    insertNode(root, 4);

    print(root);
    vector<TreeNode*> v;
    Travese(root, v);
    int temp = v[0]->val;
    v[0]->val = v[3]->val;
    v[3]->val = temp;

    print(root);

    recoverTree(root);

    print(root);

    vector<TreeNode*>::iterator it;
    for (it = v.begin(); it != v.end(); it ++) {
        cout << (*it)->val << endl;
    }

    return 0;
}
