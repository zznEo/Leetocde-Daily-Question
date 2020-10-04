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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *pre = nullptr, *cur = head, *pre0 = nullptr, *cur0 = nullptr;
        int cnt = 1;
        while(cur != nullptr && cnt <= n) {
            if(cnt == m) {
                pre0 = pre;
                cur0 = cur;
            }  
            if(cnt > m) {
                ListNode* tmp = cur->next;
                cur->next = pre;
                pre = cur;
                cur = tmp;
            } else {
                pre = cur;
                cur = cur->next;
            }
            cnt++;
        }
        if(pre0 == nullptr)
            head = pre;
        else 
            pre0->next = pre;
        cur0->next = cur;
        return head;
    }
};

Solution s1;
int main() {
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(4);
    ListNode *n5 = new ListNode(5);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    n1 = s1.reverseBetween(n1, 2, 4);
    while(n1 != nullptr) {
        cout << n1->val << " ";
        n1 = n1->next;
    }
    system("pause");
    return 0;
}