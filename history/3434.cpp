#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int maxFrequency(vector<int>& nums, int k) {
	int kFreq = 0;
	unordered_set<int> nonKNums;
	for (int num : nums) {
		if (num == k)
			kFreq++;
		else
			nonKNums.insert(num);
	}

	int maxGain = 0;

	for (int nonKNum : nonKNums) {
		int curMax = 0;
		int maxSubarray = 0;
		for (int num : nums) {
			if (num == nonKNum)
				curMax++;
			else if (num == k)
				curMax--;

			maxSubarray = max(maxSubarray, curMax);
			curMax = max(0, curMax);
		}
		maxGain = max(maxGain, maxSubarray);
	}

	return kFreq + maxGain;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 93.53%
// memory beats 60.13%
