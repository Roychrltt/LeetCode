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
		vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
			if (root == nullptr) return {};
			vector<vector<int>> ans;
			vector<int> v;
			std::function<void(int, TreeNode*, vector<int>&)> dfs = [&](int sum, TreeNode *node, vector<int>& v)
			{
				if (node == nullptr) return;
				sum += node->val;
				v.push_back(node->val);
				if (node->left == nullptr && node->right == nullptr && sum == targetSum)
					ans.push_back(v);
				dfs(sum, node->left, v);
				dfs(sum, node->right, v);
				v.pop_back();
			};
			dfs(0, root, v);
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
// runtime beats 58.39%
// memory beats 42.72%
