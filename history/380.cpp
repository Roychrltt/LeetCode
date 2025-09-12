#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

class RandomizedSet {
	std::unordered_map<int, int> map;
	std::vector<int> v;
	size_t size;
public:
	RandomizedSet() {
		size = 0;
	}

	bool insert(int val) {
		if (map.count(val))
			return false;
		v.push_back(val);
		size++;
		map[val] = size - 1;
		return true;
	}

	bool remove(int val) {
		if (!map.count(val))
			return false;
		map[v.back()] = map[val];
		v[map[val]] = v.back();
		v.pop_back();
		map.erase(val);
		size--;
		return true;
	}

	int getRandom() {
		return v[std::rand() % size];
	}
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 76.48%
// memory beats 56.42%
