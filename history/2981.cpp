#include <bits/stdc++.h>

int maximumLength(string s) {
	unordered_map<string, int> map;
	int n = s.length();
	for (int i = 0; i < n; i++)
	{
		string sub = "";
		sub += s[i];
		map[sub]++;
		for (int j = i + 1; j < n; j++)
		{
			if (s[j] != s[i])
				break;
			else
				sub += s[j];
			map[sub]++;
		}
	}
	int count = -1;
	for (auto& [a, b] : map)
		if (b >= 3)
			count = std::max(count, (int)a.length());
	return count;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 70.95%
// memory beats 47.88%
