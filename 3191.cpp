#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::vector<int>& nums) {
	int count = 0;
	int i = 0;
	while (i < nums.size()) {
		if (nums[i] == 0) {
			if (i + 2 < nums.size()) {
				for (int j = i; j < i + 3; ++j) {
					nums[j] = 1 - nums[j];
				}
				count++;
			} else return -1;
		}
		i++;
	}
	return count;
}

int main()
{
	std::vector<int> v = {0,1,1,1,0,0};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 89.37%
// memory beats 21.60%
