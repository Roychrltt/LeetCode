#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

std::vector<int> f(std::vector<int>& nums, int k, int multiplier) {
	std::vector<std::pair<int, int>> heap;
	for (int i = 0; i < nums.size(); i++)
		heap.push_back({nums[i], i});

	std::make_heap(heap.begin(), heap.end(), std::greater<>());

	while (k--) {
		std::pop_heap(heap.begin(), heap.end(), std::greater<>());
		int i = heap.back().second;
		heap.pop_back();

		nums[i] *= multiplier;
		heap.push_back({nums[i], i});
		std::push_heap(heap.begin(), heap.end(), std::greater<>());
	}
	return nums;
}

int main()
{
	std::vector<int> v = {2,1,3,6,2};
	std::vector<int> ans = f(v,5,2);
	for (int i : ans)
		std::cout << i << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 25.16%
