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
		vector<int> largestValues(TreeNode* root) {
			if (!root) return {};
			std::queue<TreeNode*> q;
			q.push(root);
			std::vector<int> ans;
			while (!q.empty())
			{
				int cur = std::numeric_limits<int>::min();
				const int size = q.size();
				for (int i = 0; i < size; i++)
				{
					TreeNode* node = q.front();
					q.pop();
					cur = std::max(cur, node->val);
					if (node->left) q.push(node->left);
					if (node->right) q.push(node->right);
				}
				ans.emplace_back(cur);
			}
			return ans;
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
// memory beats 26.80%
