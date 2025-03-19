#include <bits/stdc++.h>

int minimumLength(string s) {
	int n = s.size();
	if (n == 1) return 1;
	int l = 0, r = n - 1;
	while (l < r)
	{
		if (s[l] != s[r]) break;
		char c = s[l];
		while (l < n && s[l] == c)
			l++;
		while (r >= 0 && s[r] == c)
			r--;
	}
	return l > r ? 0 : r - l + 1;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 33.82%
