#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

void Insert(ListNode* &root, int val) {
    if (!root) {
        root = new ListNode(val);
    } else {
        ListNode* p = root;
        while(p->next) p = p->next;
        p->next = new ListNode(val);
    }
}

void Print(ListNode* root) {
    ListNode* p = root;
    while(p) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    if(l1->val > l2->val) {
        ListNode* tmp = l1;
        l1 = l2;
        l2 = tmp;
    }
    ListNode* p = l1;
    ListNode* pre = l1;
    l1 = l1->next;
    while(l1 != NULL && l2 != NULL) {
        if(l1->val > l2->val) {
            cout << l1->val << " " << l2->val << endl;
            ListNode* tmp = l2;
            l2 = l2->next;
            tmp->next = pre->next;
            pre->next = tmp;
        }else{
            l1 = l1->next;
        }
        pre = pre->next;
    }
    if(l2 != NULL) pre->next = l2;
    return p;
}

/*
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* l3 = NULL;
    if(!l1) return l2;
    if(!l2) return l1;
    ListNode* p, *q;
    if(l1->val < l2->val) {
        p = l1; q = l2;
    }else{
        p = l2; q = l1;
    }

    while(p != NULL && q != NULL) {
        if(p->val < q->val) {
            Insert(l3, p->val);
            p = p->next;
        }else{
            Insert(l3, q->val);
            q = q->next;
        }
    }
    while(p) { Insert(l3, p->val); p = p->next; }
    while(q) { Insert(l3, q->val); q = q->next; }
    return l3;
}
*/

/*
 *naive algorithm
ListNode* mergeKLists(vector<ListNode*>& lists) {
    int size = lists.size();
    ListNode* l3 = NULL;
    for (int i = 0; i < size; i ++) {
        l3 = mergeTwoLists(l3, lists[i]);
    }
    return l3;
}
*/

ListNode* mergeList(vector<ListNode*> lists, int l, int r) {
    cout << l << " x " << r << endl;
    if(l < r) {
        int mid = (l+r)/2;
        cout << "mid" << mid << l << r << endl;
        ListNode* left = mergeList(lists, l, mid);
        ListNode* right = mergeList(lists, mid+1, r);
        return mergeTwoLists(left, right);
    }else{
        cout << l << " " << r << endl;
        return lists[l];
    }

}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    int size = lists.size();
    if(size == 0) return NULL;
    return mergeList(lists, 0, size-1);
}


int main() {
    ListNode* p1, *p2, *p4;
    p1 = p2 = p4 = NULL;
    Insert(p1, 1);
    Insert(p1, 2);
    Insert(p1, 2);
    Print(p1);
    Insert(p2, 1);
    Insert(p2, 1);
    Insert(p2, 2);
    Print(p2);
    vector<ListNode*> v;
    v.push_back(p1);
    v.push_back(p2);
    ListNode* p3 = mergeKLists(v);
    Print(p3);

    /*
    ListNode* p1, *p2;
    p1 = p2 = NULL;
    Insert(p1, 1);
    Insert(p1, 3);
    Insert(p1, 5);
    Insert(p1, 7);
    Insert(p1, 9);
    Print(p1);
    Insert(p2, 2);
    Insert(p2, 4);
    Insert(p2, 6);
    Print(p2);
    vector<ListNode*> v;
    v.push_back(p1);
    v.push_back(p2);
    ListNode* p3 = mergeKLists(v);
    Print(p3);
    */
    return 0;
}
