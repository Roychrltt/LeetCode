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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
	public:
		int maxDiameter = 0;

		int height(TreeNode* node) {
			if (!node)
				return -1;
			int left = height(node->left) + 1;
			int right = height(node->right) + 1;
			maxDiameter = max(maxDiameter, left + right);
			return max(left, right);
		}

		int diameterOfBinaryTree(TreeNode* root) {
			height(root);
			return maxDiameter;
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
// memory beats 15.11%
