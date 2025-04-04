#include <bits/stdc++.h>

class Solution {
	pair<TreeNode*, int> dfs(TreeNode* root)
	{
		if (!root) return {nullptr, 0};

		auto left = dfs(root->left);
		auto right = dfs(root->right);

		if (left.second > right.second) return {left.first, left.second + 1};
		else if (left.second < right.second) return {right.first, right.second + 1};
		else return {root, left.second + 1};
	}
	public:
	TreeNode* lcaDeepestLeaves(TreeNode* root) {
		return dfs(root).first;
	}
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats %
// memory beats %
