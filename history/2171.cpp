#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <numeric>

long long f(std::vector<int>& beans) {
	int n = beans.size();
	long long ans = std::numeric_limits<long long>::max();
	long long sum = std::accumulate(beans.begin(), beans.end(), 0LL);
	std::sort(beans.begin(), beans.end());
	for (int i = 0; i < n; ++i)
		ans = std::min(ans, sum - (long long)(n - i) * beans[i]);
	return ans;
}

int main()
{
	std::vector<int> v = {66,90,47,25,92,90,76,85,22,3};
	long long ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 62.01%
// memory beats 55.02%
