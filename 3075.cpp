#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

long long f(std::vector<int>& happiness, int k) {
	std::ranges::sort(happiness, std::greater<>());
	long long ans = 0;
	for (int i = 0; i < k && happiness[i] > i; i++) {
		ans += happiness[i] - i;
	}
	return ans;
}

int main()
{
	std::vector<int> v = {1,2,3};
	int ans = f(v, 2);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 91.05%
// memory beats 31.81%
