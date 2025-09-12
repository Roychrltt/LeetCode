#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

class Solution {
	private:
		static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

	public:
		std::vector<std::vector<int>> highestPeak(std::vector<std::vector<int>>& matrix) {
			int m = matrix.size(), n = matrix[0].size();
			std::vector<std::vector<int>> ans(m, std::vector<int>(n));
			std::vector<std::vector<int>> visited(m, std::vector<int>(n));
			std::queue<std::pair<int, int>> q;

			for (int i = 0; i < m; ++i) {
				for (int j = 0; j < n; ++j) {
					if (matrix[i][j] == 1) {
						q.emplace(i, j);
						visited[i][j] = 1;
					}
				}
			}

			while (!q.empty()) {
				auto [i, j] = q.front();
				q.pop();
				for (auto [dx, dy] : dirs)
				{
					int ni = i + dx;
					int nj = j + dy;
					if (ni >= 0 && ni < m && nj >= 0 && nj < n && !visited[ni][nj]) {
						ans[ni][nj] = ans[i][j] + 1;
						q.emplace(ni, nj);
						visited[ni][nj] = 1;
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
// runtime beats 66.75%
// memory beats 44.30%
