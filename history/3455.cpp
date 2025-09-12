#include <bits/stdc++.h>

class Solution {
	std::vector<int> computeLPS(const std::string& pattern) {
		int n = pattern.size();
		std::vector<int> lps(n, 0);
		int len = 0;
		int i = 1;
		while (i < n) {
			if (pattern[i] == pattern[len])
				lps[i++] = ++len;
			else {
				if (len > 0)
					len = lps[len - 1];
				else
					i++;
			}
		}
		return lps;
	}

	void kmp(const std::string& pattern, const std::string& text, std::vector<int>& v) {
		if (pattern == "") {
			v.resize(text.length());
			std::iota(v.begin(), v.end(), 0);
			return;
		}
		int n = text.size(), m = pattern.size();
		std::vector<int> lps = computeLPS(pattern);

		int i = 0, j = 0;
		while (i < n) {
			if (text[i] == pattern[j]) {
				i++;
				j++;
			}
			if (j == m) {
				v.push_back(i - j);
				j = lps[j - 1];
			} else if (i < n && text[i] != pattern[j]) {
				if (j > 0)
					j = lps[j - 1];
				else
					i++;
			}
		}
	}

public:
	int shortestMatchingSubstring(string s, string p) {
		int n = s.size();
		int first = p.find('*');
		int second = p.find('*', first + 1);
		std::string sub1 = p.substr(0, first);
		std::string sub2 = p.substr(first + 1, second - first - 1);
		std::string sub3 = p.substr(second + 1);
		std::vector<int> v1, v2, v3;
		kmp(sub1, s, v1);
		kmp(sub2, s, v2);
		kmp(sub3, s, v3);
		int n1 = v1.size(), n2 = v2.size(), n3 = v3.size();
		if (!n1 || !n2 || !n3)
			return -1;
		if (sub2 == "" && sub3 == "")
			return sub1.size();
		if (sub1 == "" && sub3 == "")
			return sub2.size();
		if (sub2 == "" && sub1 == "")
			return sub3.size();
		int ans = INT_MAX;
		int a = 0, b = 0, c = 0;
		if (sub1 == "") {
			while (b < n2) {
				while (c < n3 && v3[c] < v2[b] + sub2.size())
					c++;
				if (c == n3)
					break;
				ans = std::min(ans, (int)(v3[c] - v2[b] + sub3.size()));
				b++;
			}
		} else if (sub2 == "") {
			while (a < n1) {
				while (c < n3 && v3[c] < v1[a] + sub1.size())
					c++;
				if (c == n3)
					break;
				ans = std::min(ans, (int)(v3[c] - v1[a] + sub3.size()));
				a++;
			}
		} else if (sub3 == "") {
			while (a < n1) {
				while (b < n2 && v2[b] < v1[a] + sub1.size())
					b++;
				if (b == n2)
					break;
				ans = std::min(ans, (int)(v2[b] - v1[a] + sub2.size()));
				a++;
			}
		} else {
			while (a < n1) {
				while (b < n2 && v2[b] < v1[a] + sub1.size())
					b++;
				if (b == n2)
					break;
				while (c < n3 && v3[c] < v2[b] + sub2.size())
					c++;
				if (c == n3)
					break;
				ans = std::min(ans, (int)(v3[c] - v1[a] + sub3.size()));
				a++;
			}
		}
		return ans == INT_MAX ? -1 : ans;
	}
};

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 98.36%
// memory beats 50.57%
