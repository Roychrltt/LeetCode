#include <bits/stdc++.h>

class Solution {
	bool check(string& s, string& sub, int k)
	{
		int cnt = 0, i = 0;
		for (char c : s)
		{
			if (c == sub[i]) i++;
			if (i == sub.size())
			{
				i = 0;
				if (++cnt >= k) return true;
			}
		}
		return false;
	}
	public:
	string longestSubsequenceRepeatedK(string& s, int k) {
		string ans = "";
		queue<string> q;
		q.push("");
		while (!q.empty()) {
			string cur = q.front(); q.pop();
			for (char c = 'a'; c <= 'z'; ++c) {
				string next = cur + c;
				if (check(s, next, k)) {
					ans = next;
					q.push(next);
				}
			}
		}
		return ans;
	}
};

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats %
// memory beats %
