#include <bits/stdc++.h>

string removeKdigits(string num, int k) {
	int n = num.size();
	stack<char> st;
	for (int i = 0; i < n; i++)
	{
		while (!st.empty() && st.top() > num[i] && k)
		{
			st.pop();
			k--;
		}
		st.push(num[i]);
	}
	while (k && !st.empty())
	{
		k--;
		st.pop();
	}
	string ans = "";
	while (!st.empty())
	{
		ans += st.top();
		st.pop();
	}
	while (ans.size() > 0 && ans.back() == '0') ans.pop_back();
	if (ans == "") return "0";
	reverse(ans.begin(), ans.end());
	return ans;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 63.19%
// memory beats 68.35%
