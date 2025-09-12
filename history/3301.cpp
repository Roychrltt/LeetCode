#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <functional>
#include <numeric>

long long f(std::vector<int>& h) {
	std::ranges::sort(h, std::greater<>()); 
	for (size_t i = 1; i < h.size(); i++) {
		h[i] = std::min(h[i], h[i - 1] - 1);
		if (h[i] <= 0) {
			return -1;
		}
	}
	return reduce(h.begin(), h.end(), 0LL);
}

int main()
{
	std::vector<int> v = {2,3,4,3};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 99.85%
// memory beats 32.60%
