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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
	public:
		TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
			if (root == nullptr || root == p || root == q)
				return root;
			TreeNode* left = lowestCommonAncestor(root->left, p, q);
			TreeNode* right = lowestCommonAncestor(root->right, p, q);
			if (left && right)
				return root;

			return left ? left : right;
		}
};

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 28.54%
// memory beats 41.83%
