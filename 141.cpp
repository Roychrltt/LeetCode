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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
	public:
		bool hasCycle(ListNode *head) {
			ListNode* slow = head;
			ListNode* fast = head;
			while (fast != nullptr && fast->next != nullptr) {
				slow = slow->next;
				fast = fast->next->next;
				if (slow == fast) {
					return true;
				}
			}
			return false;
		}
};

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 72.02%
// memory beats 33.74%
