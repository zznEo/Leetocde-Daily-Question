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
        ListNode* thead = head;
        int cnt = 0;
        while(thead != nullptr) {
            a.push_back(thead);
            thead = thead->next;
            cnt++;
        }
        ListNode *ret = head;
        for(int i = a.size() - 1,j = 1,k = 0;k < cnt-1 && j <= i;k++) {
            if(k % 2 == 0) {
                a[i]->next = nullptr;
                ret->next = a[i];
                ret = ret->next;
                i--;
            } else {
                a[j]->next = nullptr;
                ret->next = a[j];
                j++;
                ret = ret->next;
            }   
        }
        return ;
    }
private:
    vector<ListNode*> a;
};

Solution s1;
int main() {
    ListNode *r1 = new ListNode(1);
    ListNode *r2 = new ListNode(2);
    ListNode *r3 = new ListNode(3);
    ListNode *r4 = new ListNode(4);
    ListNode *r5 = new ListNode(5);
    r1->next = r2;
    r2->next = r3;
    r3->next = r4;
    r4->next = r5;
    s1.reorderList(r1);
    while(r1 != nullptr){
        cout << r1->val << " ";
        r1 = r1->next;
    }
    return 0;
}

