#include <bits/stdc++.h>

int maxSubstrings(string word) {
	vector<int> v(26, -1);
	int ans = 0;
	for (int i = 0; i < word.size(); i++)
	{
		int x = word[i] - 'a';
		if (v[x] == -1) v[x] = i;
		else if (i - v[x] >= 3)
		{
			ans++;
			for (int& k : v) k = -1;
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
