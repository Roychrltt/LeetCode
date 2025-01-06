#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
	std::unordered_map<std::string, std::vector<std::string>> v;
	for (const auto& s : strs) {
		std::string sorted = s;
		std::ranges::sort(sorted);
		v[sorted].push_back(s);
	}

	std::vector<std::vector<std::string>> ans;
	ans.reserve(v.size());
	for (auto& [_, value] : v) {
		ans.push_back(value);
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
// runtime beats 80.22%
// memory beats 86.01%
