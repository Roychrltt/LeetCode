#include <bits/stdc++.h>

vector<vector<string>> solveNQueens(int n) {
	vector<vector<string>> ans;
	vector<int> dig1(n * 2 - 1), dig2(n * 2 - 1), col(n);

	vector<string> cur(n, string(n, '.'));
	auto dfs = [&](this auto&& dfs, int r) -> void
	{
		if (r == n)
		{
			ans.push_back(cur);
			return;
		}

		for (int j = 0; j < n; j++)
		{
			if (col[j] || dig1[r - j + n - 1] || dig2[r + j]) continue;
			col[j] = 1, dig1[r - j + n - 1] = 1, dig2[r + j] = 1;
			cur[r][j] = 'Q';
			dfs(r + 1);
			cur[r][j] = '.';
			col[j] = 0, dig1[r - j + n - 1] = 0, dig2[r + j] = 0;
		}

	};
	dfs(0);
	return ans;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 80.53%
// memory beats 56.59%
