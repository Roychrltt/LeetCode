#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

class Trie {
	bool isEnd;
	Trie* next[26];

	public:
	Trie() : isEnd(false) {
		memset(next, 0, sizeof(next));
	}

	void insert(string word) {
		Trie* node = this;
		for (char c : word)
		{
			if (node->next[c - 'a'] == nullptr)
				node->next[c - 'a'] = new Trie();
			node = node->next[c - 'a'];
		}
		node->isEnd = true;
	}

	bool search(string word) {
		Trie* node = this;
		for (char c : word)
		{
			node = node->next[c - 'a'];
			if (node == nullptr)
				return false;
		}
		return node->isEnd;
	}

	bool startsWith(string prefix) {
		Trie* node = this;
		for (char c : prefix)
		{
			node = node->next[c - 'a'];
			if (node == nullptr)
				return false;
		}
		return true;
	}
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 89.37%
// memory beats 42.08%
