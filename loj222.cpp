#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int get_height(TreeNode* root) {
    int h = 0;
    TreeNode* p = root;
    while(p->left) {
        h ++;
        p = p->left;
    }
    return h;
}

bool check(TreeNode* root, int mid, int h){
    int mask = 1 << (h-1);
    TreeNode* p = root;
    while(mask) {
        if(mask & mid) {
            p = p->right;
        }else{
            p = p->left;
        }
        mask >>= 1;
    }
    if(!p) return true;
    else return false;
}

int countNodes(TreeNode* root) {
    if(root == NULL) return 0;
    // not null tree
    int h = get_height(root);
    if(h == 0) return 1;
    // only one node
    int l = 0, r = 1 << h;
    while(l < r) {
        int mid = (l+r)/2;
        if(check(root, mid, h)) {
            l = mid+1;
            // 还有更大的编号
        }else{
            r = mid;
        }
    }
    return (1 << (h-1)) + l;
}

int main() {

    return 0;
}
