#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

class Solution {
	bool isVowel(char c)
	{
		return (c == 'a' || c == 'e' || c == 'i' || c == 'o'|| c == 'u');
	}
	public:
	int maxVowels(std::string s, int k) {
		int ans = 0;
		for (int i = 0; i < k; i++)
		{
			if (isVowel(s[i]))
				ans++;
		}
		if (ans == k)
			return k;
		int j = 0;
		int tmp = ans;
		for (int i = k; i < s.length(); i++)
		{
			if (isVowel(s[j++]))
				tmp--;
			if (isVowel(s[i]))
				tmp++;
			ans = std::max(ans, tmp);
			if (ans == k)
				break;
		}
		return ans;
	}
};

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 89.66%
// memory beats 14.74%
