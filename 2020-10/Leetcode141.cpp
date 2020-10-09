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
    bool hasCycle(ListNode *head) {
        ListNode* low = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr) {
            low = low->next;
            fast = fast->next->next;
            if(low == fast) {
                return true;
            }
        }
        return false;
    }
};

Solution s1;
int main() {
    
    system("pause");
    return 0;
}