#include <bits/stdc++.h>

bool find132pattern(vector<int>& nums) {
	if (nums.size() < 3) return false;
	stack<int> st;
	vector<int> v(nums.size());
	v[0] = nums[0];
	for (int i = 1; i < nums.size(); i++)
		v[i] = min(v[i - 1], nums[i]);
	for (int i = nums.size() - 1; i >= 0; i--)
	{
		if (nums[i] == v[i]) continue;
		while (!st.empty() &&st.top() <= v[i])
			st.pop();
		if (!st.empty() && st.top() < nums[i])
			return true;
		st.push(nums[i]);
	}
	return false;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 68.67%
// memory beats 12.88%
