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

ListNode* f(ListNode* head, int k) {
	if (!head) return head; 

	ListNode* temp = head;
	int n = 1;

	while (temp->next)
	{
		temp = temp->next;
		n++;
	}

	temp->next = head;
	k = k % n;
	int i = n - k;
	while (i--)
		temp = temp->next;

	ListNode *res = temp->next;
	temp->next = nullptr;

	return res;
}

int main()
{
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next = nullptr;
	ListNode *tmp = head;
	while (tmp)
	{
		std::cout << tmp->val << std::endl;
		tmp = tmp->next;
	}
	tmp = f(head, 2);
	while (tmp)
	{
		std::cout << tmp->val << std::endl;
		tmp = tmp->next;
	}
	return 0;
}
// runtime beats 100%
// memory beats 5.37%
