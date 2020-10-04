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
    ListNode* sortList(ListNode* head) {
        if(head == nullptr)
            return ;
        auto pur = head;
        int n = 0;
        while(pur->next != nullptr) {n++; pur = pur->next;}
        QuickSortList(head, pur);
        return head;
    }
private:
    void QuickSortList(ListNode *low, ListNode* high){
        if(low == nullptr || high == nullptr || low == high)    return ;
        int pivot = low->val;
        auto i = low->next;
        auto j = low->next;
        auto i_pre = low;
        while(j != high->next){
            if(j->val < pivot){
                SwapListNode(i, j);
                i_pre = i;
                i = i->next;
            }
            j = j->next;
        }
        SwapListNode(low ,i_pre);
        QuickSortList(low, i_pre);
        QuickSortList(i, high);
    }

    void SwapListNode(ListNode* n1, ListNode* n2){
        int tmp = n1->val;
        n1->val = n2->val;
        n2->val = tmp;
    }
};

Solution s1;
void test(){
    ListNode* p1 = new ListNode(-1);
    ListNode* p2 = new ListNode(5);
    ListNode* p3 = new ListNode(3);
    ListNode* p4 = new ListNode(4);
    ListNode* p5 = new ListNode(0);
    // p1->next = p2;
    // p2->next = p3;
    // p3->next = p4;
    // p4->next = p5;

    s1.sortList(nullptr);
    while(p1 != nullptr){
        cout << p1->val << " ";
        p1 = p1->next;
    }
}

int main(){
    test();
    system("pause");
    return 0;
}