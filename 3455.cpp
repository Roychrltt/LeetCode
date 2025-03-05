#include <bits/stdc++.h>

using namespace std;

static std::vector<int> getZBox(const std::string &s) {
	int n = s.size();
	std::vector<int> z(n, 0);
	int l = 0, r = 0;
	z[0] = n;

	for (int i = 1; i < n; ++i) {
		if (i <= r) {
			z[i] = min(z[i - l], r - i + 1);
		}
		while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
			++z[i];
		}
		if (i + z[i] - 1 > r) {
			l = i;
			r = i + z[i] - 1;
		}
	}
	return z;
}

int f(std::string s, std::string p) {
	std::vector<int> tmp = {-1};
	for (int i = 0; i < p.size(); ++i) {
		if (p[i] == '*')
			tmp.push_back(i);
	}
	tmp.push_back(p.size());

	std::vector<std::string> ps;
	for (int i = 1; i < tmp.size(); ++i) {
		ps.push_back(p.substr(tmp[i - 1] + 1, tmp[i] - tmp[i - 1] - 1));
	}

	std::vector<std::vector<int>> zbox;
	for (const auto &tmps : ps) {
		string combined = tmps + "#" + s;
		vector<int> z = getZBox(combined);
		zbox.push_back(vector<int>(z.begin() + tmps.size() + 1, z.end()));
	}

	int n = s.size(), ans = INT_MAX;
	std::vector<std::vector<int>> dp(n + 1, std::vector<int>(4, -1));

	function<int(int, int)> dfs = [&](int i, int t) -> int {
		if (t == 3) return i;
		if (dp[i][t] != -1) return dp[i][t];

		int ans = INT_MAX;
		if (ps[t].empty())
			ans = min(ans, dfs(i, t + 1));
		else if (i == n)
			ans = INT_MAX;
		else if (zbox[t][i] == ps[t].size())
			ans = min(ans, dfs(i + ps[t].size(), t + 1));
		else if (t == 0)
			ans = INT_MAX;
		else
			ans = min(ans, dfs(i + 1, t));

		return dp[i][t] = ans;
	};

	for (int i = 0; i < n; ++i) {
		int j = dfs(i, 0);
		if (j != INT_MAX)
			ans = std::min(res, j - i);
	}

	return ans == INT_MAX ? -1 : ans;
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
