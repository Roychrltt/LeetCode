#include <bits/stdc++.h>

int minAnagramLength(string s) {
	int n = s.size();
	auto check = [&](int k) -> int
	{
		array<int, 26>cnt = {0};
		for (int i = 0; i < k; i++)
			cnt[s[i] - 'a']++;
		for (int i = k; i < n; i += k) {
			int cnt2[26] = {0};
			for (int j = i; j < i + k; j++)
				cnt2[s[j] - 'a']++;
			for (int j = 0; j < 26; j++)
				if (cnt[j] != cnt2[j])
					return false;
		}
		return true;
	};
	for (int i = 1; i < n; i++)
		if (n % i == 0 && check(i)) return i;
	return n;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 90.73%
// memory beats 90.24%
