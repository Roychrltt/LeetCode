#include <bits/stdc++.h>

int sumSubarrayMins(vector<int>& arr) {
	const long long M = 1e9 + 7LL;
	long long ans = 0;
	stack<vector<int>> st;
	int n = arr.size();
	vector<int> res(n);
	for (int i = 0; i < n; i++)
	{
		while (!st.empty() && st.top()[0] >= arr[i])
			st.pop();

		int j = st.empty() ? -1 : st.top()[1];
		res[i] = st.empty() ? arr[i] * (i + 1) : res[j] + arr[i] * (i - j);
		st.push({arr[i], i});
	}

	for (int i = 0; i < n; i++)
		ans = (ans + res[i]) % M;

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
