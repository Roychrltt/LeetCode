#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(const std::string& s)
{
	std::vector<int> v(26, 0);
	for (const auto& c : s)
		v[c - 'a']++;
	std::ranges::sort(v, std::greater<>());
	int ans = 0;
	for (int i = 1; i < 26; i++) {
		if (v[i] == 0)
			break;
		if (v[i] >= v[i - 1] && v[i] != 0) {
			int d = v[i - 1] == 0 ? v[i] - v[i - 1] : v[i] - v[i - 1] + 1;
			v[i] -= d;
			ans += d;
		}
	}
	return ans;
}

int main()
{
	std::string s = "aaabbbccdegf";
	int ans = f(s);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 55.08%
