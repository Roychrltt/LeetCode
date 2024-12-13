#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstring>
#include <string>
#include <numeric>

long long f(std::vector<int>& nums) {
	int n = nums.size(), ids[n];
	std::iota(ids, ids + n, 0);
	std::stable_sort(ids, ids + n, [&](int i, int j){
			return nums[i] < nums[j]; });

	long long ans = 0;
	bool vis[n + 2]; 
	memset(vis, 0, sizeof(vis));
	for (int i : ids)
		if (!vis[i + 1]) { 
			vis[i] = vis[i + 2] = true;
			ans += nums[i];
		}
	return ans;
}

int main()
{
	std::vector<int> v = {2,1,3,4,5,2};
	long long ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 79.42%
// memory beats 99.35%
