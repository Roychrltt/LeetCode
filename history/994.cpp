#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
int orangesRotting(std::vector<std::vector<int>>& grid) {
	int fresh = 0, row = grid.size(), col = grid[0].size();
	std::queue<std::pair<int, int>>q;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (grid[i][j] == 1)
				fresh++;
			else if (grid[i][j] == 2)
				q.push({i, j});
		}
	}
	if (fresh == 0) return 0;
	std::vector<std::pair<int, int>> directions = {{-1,0}, {1, 0}, {0, -1}, {0, 1}};
	int ans = 0;
	while (!q.empty())
	{
		const int n = q.size();
		bool rot = false;
		for (int i = 0; i < n; i++)
		{
			auto [x, y] = q.front();
			q.pop();
			for (auto [a, b] : directions)
			{
				int dx = x + a, dy = y + b;
				if (dx >= 0 && dx < row && dy >= 0 && dy < col && grid[dx][dy] == 1)
				{
					rot = true;
					fresh--;
					grid[dx][dy] = 2;
					q.push({dx, dy});
				}
			}
		}
		if (rot) ans++;
	}
	return fresh == 0 ? ans : -1;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 48.80%
