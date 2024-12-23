#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

class TimeMap {
	std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> map;

	public:
	TimeMap(){}

	void set(std::string key, std::string value, int timestamp) {
		map[key].emplace_back(timestamp, value);
	}

	std::string get(std::string key, int timestamp) {
		auto& pairs = map[key];
		std::pair<int, std::string> p = {timestamp, std::string({127})};
		auto i = upper_bound(pairs.begin(), pairs.end(), p);
		if (i != pairs.begin()) {
			return (i - 1)->second;
		}
		return "";
	}
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 97.20%
// memory beats 43.06%
