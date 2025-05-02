#include <bits/stdc++.h>

string pushDominoes(string s) {
	int n = s.length();
	vector<pair<int, char>> v;
	for (int i = 0; i < n; i++)
		if (s[i] != '.') v.emplace_back(i, s[i]);
	if (v.empty()) return string(n, '.');
	char prev = v[0].second;
	int idx = v[0].first;
	string ans;
	if (prev == 'R')
	{
		ans.append(idx, '.');
		ans += 'R';
	}
	else ans.append(idx + 1, 'L');

	int i = 0;
	while (++i < v.size())
	{
		char c = v[i].second;
		int x = v[i].first;
		if (c == prev) ans.append(x - idx, c);
		else if (prev == 'R' && c == 'L')
		{
			ans.append((x - idx - 1) / 2, 'R');
			if ((x - idx) % 2 == 0) ans += '.';
			ans.append((x - idx + 1) / 2, 'L');
		}
		else
		{
			ans.append(x - idx - 1, '.');
			ans += 'R';
		}
		idx = x;
		prev = c;
	}
	if (v.back().first != n - 1)
	{
		int x = n - 1 - v.back().first;
		if (prev == 'L')
			ans.append(x, '.');
		else
			ans.append(x, 'R');
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
// runtime beats %
// memory beats %
