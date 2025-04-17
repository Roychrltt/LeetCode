#include <bits/stdc++.h>

int maxWidthRamp(vector<int>& nums) {
	int n = nums.size();
	vector<pair<int, int>> minArr(n);
	minArr[0].first = nums[0];
	minArr[0].second = 0;

	for (int i = 1; i < n; i++)
	{
		if (nums[i] < minArr[i - 1].first)
		{
			minArr[i].first = nums[i];
			minArr[i].second = i;
		}
		else
		{
			minArr[i].first = minArr[i - 1].first;
			minArr[i].second = minArr[i - 1].second;
		}
	}
	int ans = 0;
	for (int i = 1; i < n; i++)
	{
		if (nums[i] >= minArr[i].first)
		{
			int j = minArr[i].second;
			while (j > 0)
			{
				if (minArr[j - 1].first <= nums[i])
					j = minArr[j - 1].second;
				else break;
			}
			ans = max(ans, i - j);
		}
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
// runtime beats 81.58%
// memory beats 21.09%
