#include <bits/stdc++.h>

long long repairCars(vector<int>& ranks, int cars) {
	int maxRank = *min_element(ranks.begin(), ranks.end());
	long long left = 1;
	long long right = (long long)cars * cars * maxRank;
	auto check = [&](long long int time) -> bool
	{
		long long count = 0;
		for (int r : ranks)
		{
			count += sqrt(time / r);
			if (count >= cars) return true;
		}
		return false;
	};
	while (left < right)
	{
		long long mid = (left + right) / 2;
		if (check(mid))
			right = mid;
		else
			left = mid + 1;
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
// runtime beats 85.12%
// memory beats 14.69%
