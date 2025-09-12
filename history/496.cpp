#include <bits/stdc++.h>

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
	unordered_map<int, int> map;
	stack<int> st;

	for (int i = nums2.size() - 1; i >= 0; i--)
	{
		while (!st.empty() && st.top() < nums2[i])
			st.pop();
		if (st.empty() || st.top() < nums2[i]) map[nums2[i]] = -1;
		else map[nums2[i]] = st.top();
		st.push(nums2[i]);
	}

	vector<int> ans(nums1.size(), 0);
	for (int i = 0; i < nums1.size(); i++)
		ans[i] = map[nums1[i]];
	return ans;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 31.63%
