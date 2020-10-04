#include <bits/stdc++.h>
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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode *l = head, *r = head->next, *ans = head->next;
        int cnt = 1;
        while(l != nullptr && l->next != nullptr) {
            ListNode *A = l;
            ListNode *B = l->next;
            ListNode *C = l->next->next;

            if(C != nullptr && C->next != nullptr) {
                A->next = B->next->next;
                B->next = A;
                l = C;
            } else {
                A->next = B->next;
                B->next = A;
                break;
            }
        }
        return ans;
    }
};

Solution s1;
int main() {
    ListNode *r1 = new ListNode(1);
    ListNode *r2 = new ListNode(2);
    ListNode *r3 = new ListNode(3);
    ListNode *r4 = new ListNode(4);
    r1->next = r2;
    r2->next = r3;
    r3->next = r4;
    r4->next = nullptr;
    r1 = s1.swapPairs(r1);
    while(r1 != nullptr) {
        cout << r1->val << " ";
        r1 = r1->next;
    }
    system("pause");
    return 0;
}