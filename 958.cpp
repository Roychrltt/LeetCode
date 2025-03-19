#include <bits/stdc++.h>

class Solution {
	int countNodes(TreeNode* node)
	{
		if (!node) return 0;
		return 1 + countNodes(node->left) + countNodes(node->right);
	}

	bool isComplete(TreeNode* node, int index, int count)
	{
		if (!node) return true;
		if (index >= count) return false;

		return isComplete(node->left, 2 * index + 1, count) && isComplete(node->right, 2 * index + 2, count);
	}
	public:
	bool isCompleteTree(TreeNode* root) {
		int count = countNodes(root);
		return isComplete(root, 0, count);
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
// memory beats 94.05%
