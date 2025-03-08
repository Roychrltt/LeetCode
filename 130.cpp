#include <bits/stdc++.h>

class Solution {
	void dfs(vector<vector<char>>& board, int i, int j, int m, int n) {
		if(i < 0 || j < 0 || i >= m || j >= n || board[i][j] != 'O') return;
		board[i][j] = '#';
		dfs(board, i - 1, j, m, n);
		dfs(board, i + 1, j, m, n);
		dfs(board, i, j - 1, m, n);
		dfs(board, i, j + 1, m, n);
	}
	public:
	void solve(vector<vector<char>>& board) {
		int m = board.size(), n = board[0].size();
		vector<vector<char>> copy = board;
		for (int i = 0; i < m; i++)
		{
			if (copy[i][0] == 'O')
				dfs(copy, i, 0, m, n);
			if (copy[i][n - 1] == 'O')
				dfs(copy, i, n - 1, m, n);
		}

		for (int i = 0; i < n; i++)
		{
			if (copy[0][i] == 'O')
				dfs(copy, 0, i, m, n);
			if (copy[m - 1][i] == 'O')
				dfs(copy, m - 1, i, m, n);
		}
		for (int i = 0; i < m; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if (copy[i][j] == '#') board[i][j] = 'O';
				else if (copy[i][j] == 'O') board[i][j] = 'X';
			}
		}
	}
};

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 77%
