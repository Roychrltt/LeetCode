#include <bits/stdc++.h>

int f(const std::string& s, int k)
{
	std::vector<int> v(26);
	for (char c : s) v[c - 'a']++;
	std::vector<int> cnt;
	for (int i : v)
		if (i) cnt.push_back(i);
	std::sort(cnt.begin(), cnt.end());
	int sum = std::accumulate(cnt.begin(), cnt.end(), 0);
	int ans = sum;
	int n = cnt.size();
	for (int i = 0; i < n; i++)
	{
		int cur = cnt[i], j = i + 1;
		while (j < n)
		{
			cur += std::min(cnt[j], cnt[i] + k);
			j++;
		}
		ans = std::min(ans, sum - cur);
	}
	return ans;
}

int main()
{
	std::string s = "aabcaba";
	int k = 0;
	int ans = f(s, k);
	std::cout << ans << std::endl;
	s = "dabdcbdcdcd";
	k = 2;
	ans = f(s, k);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats %
// memory beats %
