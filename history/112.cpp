#include <bits/stdc++.h>

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
	bool check(TreeNode* node, int sum, int targetSum)
	{
		if (!node) return sum == targetSum;
		sum += node->val;
		if (node->left && node->right)
			return check(node->left, sum, targetSum) | check(node->right, sum, targetSum);
		else if (node->left)
			return check(node->left, sum, targetSum);
		else if (node->right)
			return check(node->right, sum, targetSum);
		else
			return sum == targetSum;
	}
	public:
	bool hasPathSum(TreeNode* root, int targetSum) {
		if (!root) return false;
		return check(root, 0, targetSum);
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
// memory beats 34.99%
