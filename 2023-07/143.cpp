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
    void reorderList(ListNode* head) {
        ListNode* midNode = findMidNode(head);
        midNode->next = nullptr;
        ListNode *revertHead = revertList(midNode->next);
        mergeList(head, revertHead);
        while(revertHead != nullptr) {
            cout << revertHead->val << " ";
            revertHead = revertHead->next;
        }
    }

    ListNode* findMidNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;




        
        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* revertList(ListNode* head) {
        ListNode *cur = head;
        ListNode *pre = nullptr;
        while(cur != nullptr) {
            ListNode *tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }

    void mergeList(ListNode* head1, ListNode *head2) {
        ListNode *h1 = nullptr;
        ListNode *h2 = nullptr;
        while(head1 != nullptr && head2 != nullptr) {
            h1 = head1->next;
            h2 = head2->next;

            head1->next = head2;
            head1 = h1;

            head2->next = h1;
            head2 = h2;
        }
    }
};

int main(){
    Solution s;
    ListNode *head = new ListNode(1);
    ListNode *cur = head;
    for(int i = 2; i <= 5; i++) {
        ListNode *tmp = new ListNode(i);
        cur->next = tmp;
        cur = tmp;
    }
    s.reorderList(head);
    return 0;
}