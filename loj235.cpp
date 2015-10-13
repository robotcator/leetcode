#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left, *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

void insertNode(TreeNode* &root, int val) {
    if(root == NULL) {
        root = new TreeNode(val);
    }else{
        TreeNode* q = root;
        TreeNode* p = NULL;

    }
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

}

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    vector<int>::iterator it;
    for (it = v.begin(); it <= v.end(); it += 2) {
        cout << *it << endl;
    }

    cout << *it << endl;

    return 0;
}
