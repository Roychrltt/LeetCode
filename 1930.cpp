#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int countPalindromicSubsequence(std::string s) {
	std::vector<std::pair<int, int>> v(26);
	int len = s.length();
	for (int i = 0; i < len; i++)
	{
		int index = s[i] - 'a';
		if (v[index].first == 0)
			v[index].first = i + 1;
		else
			v[index].second = i + 1;
	}
	int ans = 0;
	for (int i = 0; i < 26; i++)
	{
		if (v[i].second - v[i].first > 1)
		{
			std::unordered_map<char, int> map;
			for (int j = v[i].first; j < v[i].second - 1; j++)
			{
				if (map.count(s[j]) == 0)
				{
					map[s[j]] = 1;
					ans++;
				}
			}
		}
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
// runtime beats 91.41%
// memory beats 47.85%
