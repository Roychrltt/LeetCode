#include <bits/stdc++.h>

class Solution {
	int sum = 0;

	void dfs(TreeNode* node)
	{
		if (!node) return;
		dfs(node->right);
		sum += node->val;
		node->val = sum;
		dfs(node->left);
	}

	public:
	TreeNode* convertBST(TreeNode* root) {
		dfs(root);
		return root;
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
// memory beats 57.05%
