#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::vector<int>& nums, std::string s, int d) {
	int n = nums.size();
	std::vector<long long> a(n);
	const int MOD = 1e9 + 7;
	for (int i = 0; i < n; i++)
	{
		a[i] = (long long)nums[i] + d * ((s[i] & 2) - 1);
	}
	std::sort(a.begin(), a.end());
	long long ans = 0;
	for (int i = 0; i < n - 1; i++) {
		long long countLeft = (i + 1) % MOD;
		long long countRight = (n - i - 1) % MOD;
		long long diff = (a[i + 1] - a[i]) % MOD;
		ans = (ans + (countLeft * countRight % MOD) * diff % MOD) % MOD;
	}

	return ans;
}

int main()
{
	std::vector<int> v = {-2,0,2};
	int ans = f(v, "RRL", 3);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 84.62%
// memory beats 52.03%
