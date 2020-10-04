class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* head = new ListNode(0);
		while (l1 != nullptr && l2 != nullptr) {
			int x = l1->val;
			int y = l2->val;
			int ans = x + y + add;
			ListNode* tmp = new ListNode(0);
			tmp->val = ans % 10;
			add = ans / 10;
			tmp->next = head->next;
			head->next = tmp;
			l1 = l1->next;
			l2 = l2->next;
		}
		while (l1 != nullptr) {
			int x = l1->val;
			ListNode* tmp = new ListNode(0);
			tmp->val = add + x;
			add = tmp->val / 10;
			tmp->val %= 10;

			tmp->next = head->next;
			head->next = tmp;
			l1 = l1->next;
		}
		while (l2 != nullptr) {
			int x = l2->val;
			ListNode* tmp = new ListNode(0);
			tmp->val = add + x;
			add = tmp->val / 10;
			tmp->val %= 10;
			
			tmp->next = head->next;
			head->next = tmp;
			l2 = l2->next;
		}
		if (add != 0) {
			ListNode* tmp = new ListNode(add);
			tmp->next = head->next;
			head->next = tmp;
		}
		head = head->next;
		ListNode* rever = nullptr, * next = nullptr;
		while (head) {
			next = head->next;
			head->next = rever;
			rever = head;
			head = next;
		}

		return rever;
	}
	void ReverList(ListNode* head) {
		int i = 0;
		/*while (head) {
			cout <<"i = " << i << " val =  " << head->val << endl;
			i++;
			head = head->next;
		}*/
		/*cout << "-------" << endl;
		i = 0;
		while (rever) {
			cout << "i = " << i << " val =  " << rever->val << endl;
			i++;
			rever = rever->next;
		}*/
	}
private:
	int add;
};
