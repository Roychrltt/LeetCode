#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
	TreeNode* helper(std::vector<int>& nums, int left, int right)
	{
		if (left > right)
			return nullptr;
		int mid = left + (right - left) / 2;
		TreeNode* root = new TreeNode(nums[mid]);
		root->left = helper(nums, left, mid - 1);
		root->right = helper(nums, mid + 1, right);
		return root;
	}
	public:
	TreeNode* sortedArrayToBST(std::vector<int>& nums) {
		return helper(nums, 0, nums.size() - 1);
	}
};

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 59.69%
// memory beats 20.40%
