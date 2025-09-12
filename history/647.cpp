#include <bits/stdc++.h>

int countSubstrings(string s) {
	int n = s.length(), ans = 0;
	auto countpds = [&](int l, int r) -> int
	{
		int count = 0;
		while (l >= 0 && r < n && s[l] == s[r])
		{
			l--;
			r++;
			count++;
		}
		return count;
	};
	for (int i = 0; i < n; ++i) {
		int even = countpds(i, i + 1);
		int odd = countpds(i, i);
		ans += even + odd;
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
// runtime beats 89.33%
// memory beats 67.75%
