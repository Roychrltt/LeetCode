#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

class Solution {
	static constexpr int DIRS[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
	public:
	int trapRainWater(std::vector<std::vector<int>>& heightMap) {
		int m = heightMap.size(), n = heightMap[0].size();
		std::priority_queue<std::tuple<int, int, int>, std::vector<std::tuple<int, int, int>>, greater<>> pq;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
					pq.emplace(heightMap[i][j], i, j);
					heightMap[i][j] = -1; 
				}
			}
		}

		int ans = 0;
		while (!pq.empty()) {
			auto [minHeight, i, j] = pq.top(); 
			pq.pop(); 
			for (auto& [dx, dy] : DIRS) {
				int x = i + dx, y = j + dy; 
				if (0 <= x && x < m && 0 <= y && y < n && heightMap[x][y] >= 0) {
					ans += max(minHeight - heightMap[x][y], 0);
					pq.emplace(max(minHeight, heightMap[x][y]), x, y);
					heightMap[x][y] = -1; 
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
// runtime beats 88.57%
// memory beats 74.10%
