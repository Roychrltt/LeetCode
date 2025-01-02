#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

class Solution {
	std::unordered_map<char, int> map = {{'a', 1}, {'e', 1}, {'i', 1}, {'o', 1}, {'u', 1}};
	bool isValid(const std::string& word)
	{
		if (map.count(word[0]) > 0 && map.count(word[word.length() - 1]) > 0)
			return true;
		return false;
	}
	public:
	std::vector<int> vowelStrings(std::vector<std::string>& words, std::vector<std::vector<int>>& q) {
		int n = words.size();
		std::vector<int> preSum(n + 1);
		preSum[0] = 0;
		for (int i = 1; i <= n; i++)
			preSum[i] = preSum [i - 1] + isValid(words[i - 1]);
		int size = q.size();
		std::vector<int> ans(size);
		for (int i = 0; i < size; i++)
		{
			ans[i] = preSum[q[i][1] + 1] - preSum[q[i][0]];
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
// memory beats 68.33%
