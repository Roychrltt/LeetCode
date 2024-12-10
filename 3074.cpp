#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::vector<int>& apple, std::vector<int>& capacity) {
	int s = reduce(apple.begin(), apple.end());
	std::ranges::sort(capacity, std::greater<>());
	int i = 0;
	while (s > 0) {
		s -= capacity[i];
		i++;
	}
	return i;
}

int main()
{
	std::vector<int> v = {1,2,3};
	std::vector<int> vv = {4,1,2,3,5};
	int ans = f(v, vv);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 25.93%
