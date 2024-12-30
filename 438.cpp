#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

std::vector<int> findAnagrams(std::string& s, std::string& p) {
	std::vector<int> map(26, 0);
	std::vector<int> mapP(26, 0);
	int n = s.length();
	int len = p.length();
	std::vector<int> ans;

	if (n < len)
		return ans;

	for (const char c : p)
		mapP[c - 'a']++;

	for (int i = 0; i < len; i++)
		map[s[i] - 'a']++;

	if (map == mapP)
		ans.push_back(0);

	for (int i = len; i < n; i++) {
		map[s[i - len] - 'a']--;
		map[s[i] - 'a']++;

		if (map == mapP)
			ans.push_back(i - len + 1);
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
// runtime beats 81.46%
// memory beats 78.67%
