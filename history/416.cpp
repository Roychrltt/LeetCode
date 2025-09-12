#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

bool canPartition(vector<int>& nums) {
	int sum = std::reduce(nums.begin(), nums.end());
	if (sum % 2 == 1) return false;
	std::vector<bool> memo(sum / 2 + 1);
	memo[0] = true;
	for (int i = 0; i < nums.size(); i++)
	{
		std::vector<bool> copy = memo;
		for (int j = 0; j < sum / 2; j++)
		{
			int cur = j + nums[i];
			if (copy[j])
			{
				if (cur == sum / 2)
					return true;
				else if(cur < sum / 2)
					memo[cur] = true;
			}
		}
	}
}
return memo[sum / 2];
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 97.14%
// memory beats 79.84%
