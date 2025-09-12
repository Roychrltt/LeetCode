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
			TreeNode* tmp = root;
			int large = std::max(p->val, q->val);
			int small = std::min(p->val, q->val);
			while (tmp != nullptr)
			{
				int cur = tmp->val;
				if (cur == large || cur == small || (cur > small && cur < large))
					break;
				else if (cur > large)
					tmp = tmp->left;
				else
					tmp = tmp->right;
			}
			return tmp;
		}
};

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 97.12%
// memory beats 25.14%
