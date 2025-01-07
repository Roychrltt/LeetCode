#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int countLife(std::vector<std::vector<int>>& board, int i, int j, int m, int n)
{
	int state = 0;
	int begin = board[i][j];
	int count = 0;
	if (i > 0)
	{
		count += board[i - 1][j];
		if (j > 0)
			count += board[i - 1][j - 1];
		if (j < n - 1)
			count += board[i - 1][j + 1];
	}
	if (i < m - 1)
	{
		count += board[i + 1][j];
		if (j > 0)
			count += board[i + 1][j - 1];
		if (j < n - 1)
			count += board[i + 1][j + 1];
	}
	if (j > 0) count += board[i][j - 1];
	if (j < n - 1) count += board[i][j + 1];
	if (begin && (count == 2 || count == 3)) state = 1;
	else if (!begin && count == 3) state = 1;
	return state;
}

void gameOfLife(std::vector<std::vector<int>>& board) {
	std::vector<std::vector<int>> copy = board;
	int m = board.size(), n = board[0].size();
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			board[i][j] = countLife(copy, i, j, m, n);
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 25.60%
