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
	bool isMirror(TreeNode *p, TreeNode *q)
	{
		if (!p && !q)
			return true;
		if (!p || !q)
			return false;
		return (p->val == q->val && isMirror(p->left, q->right) && isMirror(p->right, q->left));
	}
	public:
	bool isSymmetric(TreeNode* root) {
		return isMirror(root->left, root->right);
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
// memory beats 19.22%
