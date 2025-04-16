#include <bits/stdc++.h>

vector<int> nextGreaterElements(vector<int>& nums) {
	stack<int> st;
	for (int i = nums.size() - 1; i >= 0; i--)
	{
		while (!st.empty() && st.top() <= nums[i])
			st.pop();
		st.push(nums[i]);
	}
	vector<int> ans(nums.size());
	for (int i = nums.size() - 1; i >= 0; i--)
	{
		while (!st.empty() && st.top() <= nums[i])
			st.pop();
		if (!st.empty() && st.top() > nums[i]) ans[i] = st.top();
		else ans[i] = -1;
		st.push(nums[i]);
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
// runtime beats 62.46%
// memory beats 38.87%
