#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

std::string f(std::vector<int>& nums) {
	std::vector<std::string> num;
	for (int i : nums)
		num.push_back(std::to_string(i));
	std::ranges::sort(num, [&](std::string a, std::string b) {return a + b > b + a;});
	std::string ans = "";
	for (std::string c : num)
		ans += c;
	if (ans[0] == '0')
		return "0";
	return ans;
}

int main()
{
	std::vector<int> v = {9,39,21,8,91};
	std::string ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 86.72%
// memory beats 63.03%
