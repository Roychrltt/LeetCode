#include <bits/stdc++.h>

string removeDuplicates(string s) {
	string ans = "";
	ans += s[0];
	for (int i = 1; i < s.length(); i++)
	{
		int len = ans.size();
		if (len == 0 || s[i] != ans[len - 1]) ans += s[i];
		else ans.resize(len - 1);
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
// runtime beats 84.78%
// memory beats 47.20%
