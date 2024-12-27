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
		ListNode* swapPairs(ListNode* head) {
			ListNode dummy(0, head);
			ListNode *prev = &dummy, *cur = head;

			while (cur && cur->next) {
				ListNode* nextFirst = cur->next->next;
				ListNode* second = cur->next;

				prev->next = second;
				second->next = cur;
				cur->next = nextFirst;

				prev = cur;
				cur = nextFirst;
			}

			return dummy.next;
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
// memory beats 28.94%
