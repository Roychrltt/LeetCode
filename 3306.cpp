#include <bits/stdc++.h>

long long countOfSubstrings(string word, int k) {
	int map[128][2] = {};
	map['a'][0] = map['i'][0] = map['o'][0] = map['u'][0] = map['e'][0] = 1;
	long long int ans = 0;
	int vowel = 0, con = 0, left = 0, count = 0;
	for (int i = 0; i < word.length(); i++)
	{
		char c = word[i];
		if (map[c][0])
		{
			if (map[c][1]++ == 0) vowel++;
		}
		else con++;
		while (con > k)
		{
			char cur = word[left];
			if (map[cur][0])
			{
				if (map[cur][1]-- == 1) vowel--;
			}
			else con--;
			left++;
			count = 0;
		}
		while (vowel == 5 && con == k && map[word[left]][0] && map[word[left]][1] > 1)
		{
			map[word[left++]][1]--;
			count++;
		}
		if (vowel == 5 && con == k)
			ans += count + 1;
	}
	return ans;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 89.86%
