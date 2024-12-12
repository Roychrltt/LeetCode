#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::vector<int>& difficulty, std::vector<int>& profit, std::vector<int>& worker) {
	int n = difficulty.size();
	std::vector<std::pair<int, int>> jobs(n);
	for (int i = 0; i < n; i++) {
		jobs[i] = {difficulty[i], profit[i]};
	}
	std::ranges::sort(jobs);
	std::sort(worker.begin(), worker.end());
	int ans = 0, j = 0, max_profit = 0;
	for (int w : worker) {
		while (j < n && jobs[j].first <= w) {
			max_profit = std::max(max_profit, jobs[j++].second);
		}
		ans += max_profit;
	}
	return ans;
}

int main()
{
	std::vector<int> v1 = {2,4,6,8,10};
	std::vector<int> v2 = {10,20,30,40,50};
	std::vector<int> v3 = {4,5,6,7};
	int ans = f(v1,v2,v3);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 90.13%
// memory beats 86.75%
