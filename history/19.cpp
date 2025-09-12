#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
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
class Solution {
	public:
		ListNode* removeNthFromEnd(ListNode* head, int n) {
			std::vector<ListNode*> v;
			int count = 0;
			while (head)
			{
				count++;
				v.push_back(head);
				head = head->next;
			}
			if (n == 1 && count == 1)
				return nullptr;
			else if (n == count)
				return v[1];
			if (n < count)
				v[count - n - 1]->next = v[count - n]->next;
			return v[0];
		}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
	ListNode* res = new ListNode(0, head);
	ListNode* dummy = res;

	for (int i = 0; i < n; i++) {
		head = head->next;
	}

	while (head != nullptr) {
		head = head->next;
		dummy = dummy->next;
	}

	dummy->next = dummy->next->next;

	return res->next;        
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 11.97%
