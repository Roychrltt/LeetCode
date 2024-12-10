#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

std::string f(std::string s, int numRows) {
	if (numRows == 1 || numRows >= s.length())
		return s;
	std::vector<std::string> v(numRows);
	int a = 0, d = 1;
	for (char c : s)
	{
		v[a] += c;
		if (a == 0)
			d = 1;
		else if (a == numRows - 1)
			d = -1;
		a += d;
	}
	std::string ans = "";
	for (const auto& row : v)
		ans += row;
	return ans;
}

int main()
{
	std::string string = "PAYPALISHIRING";
	std::string ans = f(string, 3);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 58.46%
// memory beats 40.77%
