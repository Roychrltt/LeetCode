#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

std::string f(std::string s, std::vector<int>& indices) {
	size_t vsize = indices.size();
	std::string ans(vsize, 0);
	for (size_t i = 0; i < vsize; i++)
	{
		ans[indices[i]] = s[i];
	}
	return ans;
}

int main()
{
	std::string s = "ILoveChacha";
	std::vector<int> v = {4,5,6,7,0,2,1,3,10,9,8};
	std::string ans = f(s, v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 90.70%
