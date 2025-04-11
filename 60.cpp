#include <bits/stdc++.h>

string getPermutation(int n, int k) {
	string ans = "";
	int f = 1;
	for (int i = 2; i < n; i++) f *= i;
	char c = '0' + (k + f - 1) / f;
	ans += c;
	if (k > f) k %= f;
	f = n - 1;
	while (ans.size() < n)
	{
		cout << "f: " << f << " k: " << k << endl;
		c = '0' + (k + f - 1) / f;
		for (auto ch : ans)
			if (ch <= c) c++;
		ans += c;
		f--;
		if (f > 1 && k > f - 1) k = k % (f - 1) + 1;
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
