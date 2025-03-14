#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
	int n = nums.size();
	std::sort(nums.begin(), nums.end());
	std::set<std::vector<int>> set;
	std::vector<std::vector<int>> ans;
	for(int i = 0; i < n - 3; i++){
		for(int j = i + 1; j < n - 2; j++){
			long long newTarget = (long long)target - nums[i] - nums[j];
			int low = j + 1, high = n - 1;
			while (low < high){
				if (nums[low] + nums[high] < newTarget)
					low++;
				else if (nums[low] + nums[high] > newTarget)
					high--;
				else
					set.insert({nums[i], nums[j], nums[low++], nums[high--]});
			}
		}
	}
	for(auto& v : set){
		ans.push_back(v);
	}
	return ans;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats %
// memory beats %
