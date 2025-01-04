#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

bool isValidSudoku(vector<vector<char>>& board) {
	int row[9] = {0}, col[9] = {0}, grid[9] = {0};
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (board[i][j] == '.') continue;
			int x = 1 << (board[i][j] - '1');
			if ((row[i] & x) != 0) return false;
			else if ((col[j] & x) != 0) return false;
			else if ((grid[(i / 3) * 3 + j / 3] & x) != 0) return false;
			row[i] |= x;
			col[j] |= x;
			grid[(i / 3) * 3 + j / 3] |= x;
		}
	}
	return true;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 94.96%
