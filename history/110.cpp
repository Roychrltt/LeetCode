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
	public:
		bool isBalanced(TreeNode* root) {
			return root == nullptr || Height(root) != -1;
		}
		int Height(TreeNode* root) {
			if (root == NULL)  return 0;
			int left = Height(root->left);
			int right = Height(root->right);
			if (left == -1 || right == -1 || std::abs(left - right) > 1)  return -1;
			return std::max(left, right) + 1;
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
// memory beats 17.69%
