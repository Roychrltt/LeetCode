#include <bits/stdc++.h>

long long int f(std::vector<int>& nums)
{
	int n = nums.size() / 3;
	std::priority_queue<long long int> pqmax;
	std::priority_queue<long long int, std::vector<long long int>, std::greater<long long int>> pqmin;
	std::vector<long long int> pre(n), suf(n);
	long long int s1 = 0, s2 = 0;
	for (int i = 0; i < n; i++)
	{
		s1 += nums[i];
		pqmax.push(nums[i]);
	}
	for (int i = 0; i < n; i++)
	{
		s2 += nums[3 * n - 1 - i];
		pqmin.push(nums[3 * n - i - 1]);
	}
	pre[0] = s1, suf[n - 1] = s2;
	int x = pqmax.top();
	if (x > nums[n])
	{
		pqmax.pop();
		pqmax.push(nums[n]);
		pre[0] -= x - nums[n];
	}
	for (int i = 1; i < n; i++)
	{
		pre[i] = pre[i - 1];
		x = pqmax.top();
		if (x > nums[n + i])
		{
			pqmax.pop();
			pqmax.push(nums[n + i]);
			pre[i] -= x - nums[n + i];
		}
	}
	x = pqmin.top();
	if (x < nums[2 * n - 1])
	{
		pqmin.pop();
		pqmin.push(nums[2 * n - 1]);
		suf[n - 1] += nums[2 * n - 1] - x;
	}
	for (int i = n - 2; i >= 0; i--)
	{
		suf[i] = suf[i + 1];
		x = pqmin.top();
		if (x < nums[n + i])
		{
			pqmin.pop();
			pqmin.push(nums[n + i]);
			suf[i] += nums[n + i] - x;
		}
	}
	long long int ans = s1 - s2;
	ans = std::min(ans, s1 - suf[0]);
	for (int i = 0; i < n - 1; i++)
	{
		ans = std::min(ans, pre[i] - suf[i + 1]);
		std::cout << i << " " << ans << std::endl;
	}
	ans = std::min(ans, pre[n - 1] - s2);
	return ans;
}

int main()
{
	std::vector<int> v = {3,1,2,6,3,9,8,7,6,  1,3,4,9,5,7,12,4,65,   8,9,7,5,3,3,3,1,32};
	long long int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 96.65%
// memory beats 71.13%
