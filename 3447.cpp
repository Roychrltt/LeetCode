#include <bits/stdc++.h>

std::vector<int> f(std::vector<int>& v, std::vector<int>& e)
{
	std::vector<int> seen(1e5 + 2, -1);
	for (int i = 0; i < e.size(); i++)
		if (seen[e[i]] == -1) seen[e[i]] = i;
	int n = v.size();
	std::vector<int> ans(n, -1);
	for (int i = 0; i < n; i++)
	{
		int x = v[i];
		for (int j = 1; j * j <= x; j++)
		{
			if (seen[j] >= 0 && x % j == 0)
				if (ans[i] < 0 || ans[i] > seen[j]) ans[i] = seen[j];
			if (x % j == 0 && seen[x / j] >= 0)
				if (ans[i] < 0 || ans[i] > seen[x / j]) ans[i] = seen[x / j];
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
// runtime beats %
// memory beats %
