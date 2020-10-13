#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode *traver = head;
        head = head->next;
        while(traver != nullptr && traver->next != nullptr) {
            ListNode *A = traver, *B = traver->next, *C = traver->next->next;
            if(C != nullptr && C->next != nullptr) {
                ListNode *D = C->next;
                A->next = D;
                B->next = A;
                D->next = C;
                traver = C;
            } else {
                B->next = A;
                A->next = C;
                break;
            }
        }
        return head;
    }
};

Solution s1;
int main() {
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(2);
    ListNode *l3 = new ListNode(3);
    ListNode *l4 = new ListNode(4);

    l1->next = l2;
    l2->next = l3;
    l3->next = l4;

    ListNode *t = s1.swapPairs(l1);
    while(t != nullptr){
        cout << t->val << " ";
        t = t->next;
    }
    return 0;
}