#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::vector<int>& arr) {
	std::unordered_map<int, int> map;
	for (int i : arr) {
		map[i]++;
	}

	std::vector<int> count;
	for (const auto& p : map) {
		count.push_back(p.second);
	}
	std::ranges::sort(count, std::greater<>());

	int sum = 0, i = 0;
	while (sum < arr.size() / 2)
	{
		sum += count[i];
		i++;
	}
	return i;
}

int main()
{
	std::vector<int> v = {3,3,3,3,5,5,5,2,2,7};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 82.85%
// memory beats 69.73%
