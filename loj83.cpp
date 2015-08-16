#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void Insert(ListNode* &root, int val) {
    if(!root) {
        root = new ListNode(val);
    }else{
        ListNode* p = root;
        while (p->next) {
            p = p->next;
        }
        p->next = new ListNode(val);
    }
}

void print(ListNode* root) {
    if(!root) return ;
    printf("%d\n", root->val);
    print(root->next);
}

ListNode* deleteDuplicates(ListNode* head) {
    if(!head || !head->next) return head;
    ListNode* p, *q;
    p = head; q = head->next;
    while (q) {
        while (q && p->val == q->val) {
            ListNode *temp = q;
            q = q->next;
            free(temp);
        }
        if (q) {
            p->next = q;
            p = p->next;
            q = q->next;
        }
    }
    p->next = NULL;
    return head;
}

int main() {
    ListNode* root = NULL;
    Insert(root, 2);
    Insert(root, 2);
    Insert(root, 2);
    Insert(root, 3);
    Insert(root, 4);
    print(root);
    root = deleteDuplicates(root);
    print(root);
    return 0;
}
