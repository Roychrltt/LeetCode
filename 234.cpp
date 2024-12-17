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
		bool isPalindrome(ListNode* head) {
			std::vector<int> vals;
			while (head)
			{
				vals.push_back(head->val);
				head = head->next;
			}

			int left = 0, right = vals.size() - 1;
			while (left < right && vals[left] == vals[right]) {
				left++;
				right--;
			}
			return left >= right;
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
// memory beats 7.64%
