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
    ListNode* getKthFromEnd(ListNode* head, int k) {
		if(head == nullptr)
			return nullptr;
		int l = 0, r = 0;
		ListNode *lhead = head, *rhead = head;
		while(rhead != nullptr && r < k){
			rhead = rhead->next;
			r++;
		}
		while(rhead != nullptr){
			lhead = lhead->next;
			rhead = rhead->next;
		}
		return lhead;
    }
};
Solution s1;
int main() {
    ListNode *a1 = new ListNode(1);
	ListNode *a2 = new ListNode(2);
	ListNode *a3 = new ListNode(3);
	ListNode *a4 = new ListNode(4);
	ListNode *a5 = new ListNode(5);
	a1->next = a2;
	a2->next = a3;
	a3->next = a4;
	a4->next = a5;
	a1 = s1.getKthFromEnd(a1, 2);
	while(a1 != nullptr){
		cout << a1->val << " ";
		a1 = a1->next;
	}
    system("pause");
    return 0;
}