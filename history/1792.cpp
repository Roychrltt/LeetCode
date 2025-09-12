#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

double f(std::vector<std::vector<int>>& classes, int extraStudents) {
	std::priority_queue<std::tuple<double, int, int>> q;

	auto diff = [](int x, int y) -> double {
		return (double)(x + 1) / (y + 1) - (double)x / y;
	};

	double ans = 0.;
	for (const auto& c : classes) {
		int x = c[0], y = c[1];
		ans += (double)x / y;
		q.emplace(diff(x, y), x, y);
	}
	for (int _ = 0; _ < extraStudents; ++_) {
		auto [d, x, y] = q.top();
		q.pop();
		ans += d;
		q.emplace(diff(x + 1, y + 1), x + 1, y + 1);
	}
	return ans / classes.size();
}

int main()
{
	std::vector<std::vector<int>> v = {{1,2}, {3,5}, {2,2}};
	double ans = f(v, 2);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 64.10%
// memory beats 39.10%
