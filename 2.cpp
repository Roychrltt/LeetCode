#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* f(ListNode* l1, ListNode* l2) {
	int sum = l1->val + l2->val;
	ListNode *ans = new ListNode(sum % 10);
	int carry = sum / 10;
	ListNode *temps = ans;
	l1 = l1->next;
	l2 = l2->next;
	while (l1 || l2 || carry)
	{
		int av = (l1 == nullptr) ? 0 : l1->val;
		int bv = (l2 == nullptr) ? 0 : l2->val;
		sum = av + bv + carry;
		carry = sum / 10;
		temps->next = new ListNode(sum % 10);
		temps = temps->next;
		if (l1)
			l1 = l1->next;
		if (l2)
			l2 = l2->next;
	}
	return ans;
}

int main()
{
	ListNode *n1 = new ListNode(2);
	n1->next = new ListNode(4);
	n1->next->next = new ListNode(3);
	n1->next->next->next =nullptr;

	ListNode *n2 = new ListNode(5);
	n2->next = new ListNode(6);
	n2->next->next = new ListNode(4);
	n2->next->next->next =nullptr;

	ListNode *n3 = f(n1, n2);
	while (n3)
	{
		std::cout << n3->val;
		n3 = n3->next;
	}
	std::cout << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 36.06%
