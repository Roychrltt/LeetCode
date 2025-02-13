#include <bits/stdc++.h>

class NumberContainers {
	unordered_map<int, int> nums;
	unordered_map<int, set<int>> idxs;
public:
	NumberContainers() {
		return;
	}

	void change(int index, int number) {
		if (nums.count(index) > 0)
		{
			int prev = nums[index];
			idxs[prev].erase(index);
		}
		nums[index] = number;
		idxs[number].insert(index);
	}

	int find(int number) {
		if (idxs[number].size() > 0)
			return *idxs[number].begin();
		else
			return -1;
	}
};

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 70.61%
// memory beats 20.46%
