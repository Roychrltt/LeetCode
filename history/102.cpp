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
		std::vector<std::vector<int>> levelOrder(TreeNode* root) {
			std::vector<std::vector<int>> ans;
			if (root == NULL)
				return ans;
			std::queue<TreeNode*> q;
			q.push(root);
			while (!q.empty())
			{
				const int s = q.size();
				std::vector<int> v;
				for (int i = 0; i < s; i++)
				{
					TreeNode* node = q.front();
					q.pop();
					if (node->left != NULL)
						q.push(node->left);
					if (node->right != NULL)
						q.push(node->right);
					v.push_back(node->val);
				}
				ans.push_back(std::move(v));
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
// memory beats 34.75%
