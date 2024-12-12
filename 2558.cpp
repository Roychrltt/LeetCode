#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <numeric>
#include <cmath>

long long f(std::vector<int>& gifts, int k) {
	std::make_heap(gifts.begin(), gifts.end());
	while (k-- && gifts[0] > 1) {
		std::pop_heap(gifts.begin(), gifts.end());
		gifts.back() = std::sqrt(gifts.back());
		std::push_heap(gifts.begin(), gifts.end());
	}
	return std::accumulate(gifts.begin(), gifts.end(), 0LL);
}

int main()
{
	std::vector<int> v = {26,9,102,8,4};
	int ans = f(v, 5);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 61.64%
// memory beats 94.35%
