#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

std::vector<int> findErrorNums(std::vector<int>& nums) {
	long long int n = nums.size(), sum = 0, sum2 = 0;
	for (int x : nums)
	{
		sum += x;
		sum2 += x * x;
	}
	int diff = n * (n + 1) / 2 - sum;
	int diff2 = n * (n + 1) * (2 * n + 1) / 6 - sum2;
	int one = (diff2 / diff + diff) / 2;
	return {one - diff, one};
}

std::vector<int> findErrorNums(std::vector<int>& nums) {
	for (int i = 0; i < nums.size(); ++i)
		while (nums[i] != nums[nums[i] - 1])
			swap(nums[i], nums[nums[i] - 1]);
	for (int i = 0; i < nums.size(); ++i) 
		if (nums[i] != i + 1)
			return {nums[i], i + 1};
	
	return {};
}


std::vector<int> findErrorNums(std::vector<int>& nums) {
	int n = nums.size();
	int sum = 0, xor1 = 0, xor2 = 0;
	int dup = -1, mis = 1;
	std::vector<int> ans(2);
	for (int i = 0; i < n; ++i)
		sum ^= (i + 1) ^ nums[i];
	int t = sum & -sum;
	for (int i = 1; i < n + 1; ++i) {
		if (t & i) xor1 ^= i;
		else xor2 ^= i;
	}
	for (int i = 0; i < n; ++i) {
		if (t & nums[i]) xor1 ^= nums[i];
		else xor2 ^= nums[i];
	}
	int count = 0;
	for (int i = 0; i < n; ++i)
		if (nums[i] == xor1)
			count++;
	if (count == 0) { dup = xor2; mis = xor1; }
	else { dup = xor1; mis = xor2; }

	ans[0] = dup; ans[1] = mis;
	return ans;
}

std::vector<int> findErrorNums(std::vector<int>& nums) {
	int n = nums.size();
	int sum = 0, xor1 = 0, xor2 = 0;
	for (int i = 0; i < n; ++i)
		sum ^= (i + 1) ^ nums[i];

	int count = __builtin_ctz(sum);
	for (int i = 1; i < n + 1; ++i) {
		if (i & (1 << count)) xor1 ^= i;
		else xor2 ^= i;
	}
	for (int i = 0; i < n; ++i) {
		if (nums[i] & (1 << count)) xor1 ^= nums[i];
		else xor2 ^= nums[i];
	}
	for (int i = 0; i < n; ++i)
	{
		if (nums[i] == xor1)
			return {xor1, xor2};
		else if (nums[i] == xor2)
			return {xor2, xor1};
	}
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 66.52%
