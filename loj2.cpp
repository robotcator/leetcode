#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* sum = NULL;
        ListNode* p3 = sum;
        int carray = 0;

        while (p1 != NULL && p2 != NULL) {
            ListNode* temp = new ListNode(0);
            temp->val = (p1->val + p2->val + carray) % 10;
            carray = (p1->val + p2->val + carray) / 10;

            if (sum == NULL) {

            }
            p3->next = temp;
            p3 = temp;

            p1 = p1->next; p2 = p2->next;
        }

        while(p1 != NULL) {
            ListNode* temp = new ListNode(0);
            temp->val = (p1->val + carray) % 10;
            carray = (p1->val + carray) / 10;
            p3->next = temp;
            p3 = temp;
            p1 = p1->next;
        }

        while(p2 != NULL) {
            ListNode* temp = new ListNode(0);
            temp->val = (p2->val + carray) % 10;
            carray = (p2->val + carray) / 10;
            p3->next = temp;
            p3 = temp;
            p2 = p2->next;
        }

        return sum;
    }
};

void insert(ListNode *l, int x) {
        ListNode* p = l;
        if (p == NULL) {
            p = new ListNode(x);
        } else {
            while (p->next != NULL) p = p->next;
            p->next = new ListNode(x);
        }
}

void print(ListNode *l) {
    ListNode* p = l;
    while (p != NULL) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    Solution* s = new Solution();
    ListNode *l1, *l2;
    l1 = new ListNode(0);
    l2 = new ListNode(0);
    int m, n, x;
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; i ++) {
        scanf("%d", &x);
        insert(l1, x);
        print(l1);
    }
    print(l1);

    for (int i = 0; i < n; i ++) {
        scanf("%d", &x);
        insert(l2, x);
    }
    print(l2);

    ListNode *sum = s->addTwoNumbers(l1, l2);

    print(sum);

    return 0;
}
