#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

const int dx[5] = {0, 1, -1, 0, 0};
const int dy[5] = {0, 0, 0, 1, -1};

class Solution {
	public:
		int minCost(std::vector<std::vector<int>>& grid) {
			int m = grid.size(), n = grid[0].size();
			std::deque<std::tuple<int, int, int>> deque;
			deque.emplace_back(0, 0, 0);
			std::vector<std::vector<bool>> visited(m, std::vector<bool>(n));
			while (!deque.empty()) {
				auto t = deque.front();
				deque.pop_front();
				int w = std::get<0>(t), y = std::get<1>(t), x = std::get<2>(t);
				if (visited[y][x]) continue;
				visited[y][x] = true;
				if (y == m - 1 && x == n - 1)
					return w;
				for (int k = 1; k <= 4; k++)
				{
					int nx = x + dx[k], ny = y + dy[k];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m)
						continue;
					if (grid[y][x] == k) 
						deque.emplace_front(w, ny, nx);
					else
						deque.emplace_back(w + 1, ny, nx);
				}
			}
			return 0;
		}
};

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 69.70%
// memory beats 56.41%
