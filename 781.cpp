#include <bits/stdc++.h>

int numRabbits(vector<int>& a) {
	sort(a.begin(), a.end());
	int sum = 0;
	int cur = a[0];
	int i = 0;
	while (i < a.size())
	{
		sum += a[i] + 1;
		int j = 0;
		while (j < a[i] + 1 && i + j < a.size() && a[i + j] == a[i])
			j++;
		i += j;
	}
	return sum;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 97.93%
