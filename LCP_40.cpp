#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::vector<int>& cards, int cnt) {
	std::ranges::nth_element(cards, cards.end() - cnt); 
	int s = std::reduce(cards.end() - cnt, cards.end());
	if (s % 2 == 0)
		return s;

	int n = cards.size();

	int mx[2] = {INT_MIN / 2, INT_MIN / 2}; 
	for (int i = 0; i < n - cnt; i++) {
		int v = cards[i];
		mx[v % 2] = std::max(mx[v % 2], v);
	}


	int mn[2] = {INT_MAX / 2, INT_MAX / 2};
	for (int i = n - cnt; i < n; i++) {
		int v = cards[i];
		mn[v % 2] = std::min(mn[v % 2], v);
	}

	return std::max(s + std::max(mx[0] - mn[1], mx[1] - mn[0]), 0);
}

int main()
{
	std::vector<int> v = {1,2,10,1111};
	int ans = f(v, 2);
	std::cout << ans << std::endl;
	return 0;
}
