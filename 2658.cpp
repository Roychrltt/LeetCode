#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

// DFS
class Solution {
    static constexpr int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        auto dfs = [&](this auto&& dfs, int x, int y) -> int
        {
            if (x < 0 || x >= m || y < 0 || y >= n || !grid[x][y]) return 0;
            int sum = grid[x][y];
            grid[x][y] = 0;
            for (auto&d : dirs)
                sum += dfs(x + d[0], y + d[1]);
            return sum;
        };
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                ans = max(ans, dfs(i, j));
        
        return ans;
    }
};

// BFS
class Solution {
    static constexpr int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!grid[i][j]) continue;
                int cur = 0;
                queue<pair<int, int>> q;
                q.emplace(i, j);
                while (!q.empty())
                {
                    auto p = q.front();
                    q.pop();
                    int x = p.first, y = p.second;
                    cur += grid[x][y];
                    grid[x][y] = 0;
                    for (auto d : dirs)
                    {
                        int dx = x + d[0], dy = y + d[1];
                        if (dx >= 0 && dx < m && dy >= 0 && dy < n && grid[dx][dy])
                            q.emplace(dx, dy);
                    }
                }
                ans = max(ans, cur);
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
// runtime beats 66.73%
// memory beats 98.42%
