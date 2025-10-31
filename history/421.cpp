#include <bits/stdc++.h>

class TrieNode {
	public:
		TrieNode* children[2];

		TrieNode()
		{
			children[0] = nullptr;
			children[1] = nullptr;
		}
};

class Trie {
	private:
		TrieNode* root;

	public:
		Trie() { root = new TrieNode(); }

		void insert(int num)
		{
			TrieNode* node = root;
			for (int i = 31; i >= 0; i--)
			{
				if (num & (1 << i))
				{
					if (node->children[1] == nullptr) node->children[1] = new TrieNode();
					node = node->children[1];
				}
				else
				{
					if (node->children[0] == nullptr) node->children[0] = new TrieNode();
					node = node->children[0];
				}
			}
		}

		int query(int num)
		{
			int ans = 0;
			TrieNode* node = root;
			for (int i = 31; i >= 0; i--)
			{
				if (num & (1 << i))
				{
					if (node->children[0]) node = node->children[0];
					else
					{
						ans |= (1 << i);
						node = node->children[1];
					}
				}
				else
				{
					if (node->children[1])
					{
						ans |= (1 << i);
						node = node->children[1];
					}
					else node = node->children[0];

				}
			}
			return ans;
		}
};

int f(std::vector<int>& nums)
{
	Trie trie;
	for (int x : nums) trie.insert(x);
	int ans = 0;
	for (int x : nums)
	{
		int xx = trie.query(x);
		ans = std::max(ans, xx ^ x);
	}
	return ans;
}

int main()
{
	std::vector<int> v = {14,70,53,83,49,91,36,80,92,51,66,70};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats %
// memory beats %
