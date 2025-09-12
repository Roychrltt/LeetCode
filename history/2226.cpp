#include <bits/stdc++.h>

int maximumCandies(vector<int>& c, long long k) {
	int n = c.size();
	long long left = 1, right = 0;
	for (auto cc : c)
		right += cc;
	if (right < k) return 0;
	right /= k;
	auto check = [&](int x) -> bool
	{
		long long count = 0;
		for (auto cc : c)
		{
			count += cc / x;
			if (count >= k) return true;
		}
		return false;
	};
	while (left <= right)
	{
		long long mid = (left + right) / 2;
		if (check(mid))
			left = mid + 1;
		else
			right = mid - 1;
	}
	return right;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 98.81%
// memory beats 41.19%
