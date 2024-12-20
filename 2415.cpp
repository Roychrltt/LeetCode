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
// Using stack to do dfs
	TreeNode* reverseOddLevels(TreeNode* root)
	{
        if (root == nullptr) return root; 

        std::stack<std::tuple<TreeNode*, TreeNode*, bool>> stk;
        stk.push({root->left, root->right, true});

        while (!stk.empty())
		{
            auto [p, q, isOdd] = stk.top();
            stk.pop();

            if (p == nullptr) continue;

            if (isOdd)
                std::swap(p->val, q->val);

            stk.push({p->left, q->right, !isOdd});
            stk.push({p->right, q->left, !isOdd});
        }

        return root;
    }
	public:
		TreeNode* reverseOddLevels(TreeNode* root) {
			dfs(root->left, root->right, true);
			return root;
		}
	private:
		void dfs(TreeNode* p, TreeNode* q, const bool isOdd) {
			if (p == nullptr)
				return ;
			if (isOdd)
				swap(p->val, q->val);
			dfs(p->left, q->right, !isOdd);
			dfs(p->right, q->left, !isOdd);
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
// memory beats 65.15%
