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
	ListNode* swapNodes(ListNode* head, int k) {
		ListNode *left = head, *right = head;
		for (int i = 0; i < k-1; i++)
			right = right->next;

		ListNode *end = right;
		while (right->next) {
			left = left->next;
			right = right->next;
		}

		swap(end->val, left->val);

		return head;
	}
};

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 40.26%
