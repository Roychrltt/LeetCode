#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int count(TreeNode* root, int l_depth) {
	if (!root) return 0;
	int r_depth = countLevels(root->right);
	if (l_depth == r_depth)
		return (1 << l_depth) + count(root->right, r_depth - 1);
	else
		return (1 << r_depth) + count(root->left, l_depth - 1);
}

int countLevels(TreeNode* root) {
	int level = 0;
	while (root != nullptr) {
		level++;
		root = root->left;
	}
	return level;
}

int countNodes(TreeNode* root) {
	int depth = countLevels(root);
	return count(root, depth - 1);
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 66.35%
