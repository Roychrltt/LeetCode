#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

std::vector<long long> f(long long finalSum) {
	if (finalSum % 2) return {};
	std::vector<long long> ans;
	for (long long i = 2; i <= finalSum; i += 2) {
		ans.push_back(i);
		finalSum -= i;
	}
	ans.back() += finalSum;
	return ans;
}

int main()
{
	std::vector<long long> v = f(10000000000000);
	for (const auto& i : v)
		std::cout << i << std::endl;
	return 0;
}
// runtime beats 82.56%
// memory beats 69.96%
