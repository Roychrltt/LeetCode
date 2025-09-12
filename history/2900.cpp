#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
	std::vector<std::string> ans;
	ans.emplace_back(words[0]);
	int prev = groups[0];
	for (int i = 1; i < words.size(); i++)
	{
		if (groups[i] == prev) continue;
		prev = groups[i];
		ans.emplace_back(words[i]);
	}
	return ans;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 54.80%
