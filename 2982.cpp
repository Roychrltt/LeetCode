#include <bits/stdc++.h>

int maximumLength(string s) {
	unordered_map<string, int> map;
	int n = s.length();
	string sub = "";
	char prev = s[0];
	for (int i = 0; i < n; i++)
	{
		if (s[i] != prev)
		{
			map[sub]++;
			prev = s[i];
			sub = "";
			sub += s[i];
		}
		else
			sub += s[i];
	}
	map[sub]--;
	int count = -1;
	for (auto& [a, b] : map)
	{
		if (b == 1 && a.length() >= 2)
		{
			if (map.count(a.substr(0, a.length() - 1)) > 0)
				count = std::max(count, (int)a.length() - 1);
			else
				count = std::max(count, (int)a.length() - 2);
		}
		else if (b == 2 && a.length() >= 1)
			count = std::max(count, (int)a.length() - 1);
		else if (b >= 3)
			count = std::max(count, (int)a.length());
	}
	return count > 0 ? count : -1;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 75.11%
// memory beats 67.58%
