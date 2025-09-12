#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::vector<int>& arr, int k) {
	std::unordered_map<int, int> freq;
	for (int num: arr) {
		freq[num]++;
	}

	std::vector<std::pair<int, int>> v(freq.begin(), freq.end());
	std::sort(v.begin(), v.end(), [](const auto u, const auto v) {return u.second < v.second;});

	int ans = v.size();
	for (auto [value, occ]: v) {
		if (k >= occ) {
			--ans;
			k -= occ;
		} else {
			break;
		}
	}
	return ans;
}

int main()
{
	std::vector<int> v = {4,3,1,1,3,3,2};
	int ans = f(v, 3);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 81.00%
// memory beats 44.56%
