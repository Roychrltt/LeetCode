#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <cmath>

int f(std::vector<int>& grades) {
	return std::sqrt(0.25 + 2 * grades.size()) - 0.5 + 1e-9;
}

int main()
{
	std::vector<int> v = {1,2,3,4,5,6,7,8,9,10};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 40.72%
