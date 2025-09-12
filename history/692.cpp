#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

std::vector<std::string> topKFrequent(std::vector<std::string>& words, int k) {
	std::unordered_map<std::string, int> map;
	for (auto& word : words)
		map[word]++;

	std::vector<std::string> ans;
	for (auto& [key, value] : map)
		ans.emplace_back(key);

	std::ranges::sort(ans, [&](const auto& a, const auto& b) {
			return map[a] == map[b] ? a < b : map[a] > map[b];
			});
	ans.erase(ans.begin() + k, ans.end());
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
// memory beats 82.04%
