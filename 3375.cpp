#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::vector<int>& nums, int k) {
	int cnt = 0;
	bool ok = true;
	array<int, 101> a = {0};
	for (int i : nums)
	{
		if (i < k) return -1;
		if (i > k && a[i]++ == 0) cnt++;
	}
	return cnt;
}

int main()
{
	std::vector<int> v = {5,2,5,4,5};
	int ans = f(v, 2);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 80.19%
// memory beats 80.09%
