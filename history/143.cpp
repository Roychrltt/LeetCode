#include <bits/stdc++.h>

void reorderList(ListNode* head) {
	if (!head || !head->next) return;

	ListNode* slow = head;
	ListNode* fast = head;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	ListNode* second = slow->next;
	slow->next = nullptr;
	ListNode* nn = nullptr;

	while (second) {
		ListNode* temp = second->next;
		second->next = nn;
		nn = second;
		second = temp;
	}

	ListNode* first = head;
	second = nn;

	while (second) {
		ListNode* temp1 = first->next;
		ListNode* temp2 = second->next;
		first->next = second;
		second->next = temp1;
		first = temp1;
		second = temp2;
	}
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats %
// memory beats %
