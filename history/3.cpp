#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::string s) {
	std::unordered_map<char, size_t> map;
	size_t begin = 0, ans = 0;

	for (size_t i = 0; i < s.size(); ++i)
	{
		char c = s[i];
		if (map.count(c) && map[c] >= begin)
		{
			begin = map[c] + 1;
		}
		map[c] = i;
		ans = std::max(ans, i - begin + 1);
	}
	return static_cast<int>(ans);
}

int main()
{
	std::string string = "abcabcbb";
	int ans = f(string);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 74.61%
// memory beats 65.83%
