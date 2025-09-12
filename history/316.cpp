#include <bits/stdc++.h>

string removeDuplicateLetters(string s) {
	array<int, 26> lastSeen = {0};
	array<int, 26> vis = {0};
	for (int i = 0; i < s.size(); i++)
		lastSeen[s[i] - 'a'] = i;
	stack<char> st;
	for (int i = 0; i < s.size(); i++)
	{
		if (vis[s[i] - 'a']) continue;

		while (!st.empty() && s[i] < st.top() && i < lastSeen[st.top() - 'a'])
		{
			vis[st.top() - 'a'] = 0;
			st.pop();
		}
		vis[s[i] - 'a'] = 1;
		st.push(s[i]);
	}
	string ans = "";
	while (!st.empty())
	{
		ans = st.top() + ans;
		st.pop();
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
// runtime beats 100%
// memory beats 56.27%
