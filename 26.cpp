#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::vector<int>& nums) {
	int j = 1;
	for(int i = 1; i < nums.size(); i++){
		if(nums[i] != nums[i - 1]){
			nums[j] = nums[i];
			j++;
		}
	}
	return j;
}

int main()
{
	std::vector<int> v = {0,0,1,1,1,2,2,3,3,4};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 19.89%
