#include <bits/stdc++.h>

int numberOfSubstrings(string s) {
	int map[3] = {};
	int count = 0, ans = 0, left = 0, extra = 1;
	int n = s.length();
	for (int i = 0; i < n; i++)
	{
		if (map[s[i] - 'a']++ == 0) count++;
		if (count < 3) continue;
		while (map[s[left] - 'a'] > 1)
		{
			map[s[left++] - 'a']--;
			extra++;
		}
		ans += (n - i) * extra;
		extra = 0;
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
// runtime beats 91.06%
// memory beats 81.05%
