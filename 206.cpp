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
		ListNode* reverseList(ListNode* head) {
			ListNode* node = nullptr;

			while (head != nullptr) {
				ListNode* temp = head->next;
				head->next = node;
				node = head;
				head = temp;
			}

			return node;
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
// memory beats 21.32%
