#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::vector<int>& seats, std::vector<int>& students) {
	std::sort(seats.begin(), seats.end());
	std::sort(students.begin(), students.end());
	int res = 0;
	for (int i = 0; i < seats.size(); i++) {
		res += std::abs(seats[i] - students[i]);
	}
	return res;
}

int main()
{
	std::vector<int> v1 = {1,4,5,7};
	std::vector<int> v2 = {2,3,6,8};
	int ans = f(v1, v2);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 18.55%
