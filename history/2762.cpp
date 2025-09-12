#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <string>

long long f(std::vector<int>& nums) {
	long long ans = 0;
	std::map<int, int> count;
	int left = 0;
	for (int right = 0; right < nums.size(); right++) {
		count[nums[right]]++;
		while (count.rbegin()->first - count.begin()->first > 2) {
			int x = nums[left++];
			if (--count[x] == 0) {
				count.erase(x);
			}
		}
		ans += right - left + 1;
	}
	return ans;
}

int main()
{
	std::vector<int> v = {5,4,2,4,6,8,8,7,9,6,0,1};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 94.05%
// memory beats 79.40%
