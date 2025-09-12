#include <bits/stdc++.h>

class SuffixArray {
	int n;
	std::vector<int> SA, tempSA, RA, tempRA, cnt;
	std::string T;

	int getRA(int i) const {
		return (i < n) ? RA[i] : 0;
	}

	void radix_sort(int k) {
		int max_val = std::max(300, n);
		cnt.assign(max_val, 0);

		for (int i = 0; i < n; ++i)
			cnt[getRA(i + k)]++;

		for (int i = 1; i < max_val; ++i)
			cnt[i] += cnt[i - 1];

		for (int i = n - 1; i >= 0; --i) {
			int idx = getRA(SA[i] + k);
			tempSA[--cnt[idx]] = SA[i];
		}
		SA = tempSA;
	}

	public:
	std::vector<int> build(const std::string& input) {
		T = input + "$";
		n = T.size();

		SA.resize(n);
		tempSA.resize(n);
		RA.resize(n);
		tempRA.resize(n);

		for (int i = 0; i < n; ++i) {
			SA[i] = i;
			RA[i] = T[i];
		}

		for (int k = 1; k < n; k <<= 1) {
			radix_sort(k);
			radix_sort(0);

			tempRA[SA[0]] = 0;
			int r = 0;

			for (int i = 1; i < n; ++i) {
				if (RA[SA[i]] != RA[SA[i - 1]] || getRA(SA[i] + k) != getRA(SA[i - 1] + k))
					r++;
				tempRA[SA[i]] = r;
			}
			RA = tempRA;

			if (RA[SA[n - 1]] == n - 1)
				break;
		}
		return SA;
	}
};

std::vector<int> buildSA(const std::string& s) {
	SuffixArray sa;
	return sa.build(s);
}

std::string f(std::string word, int numFriends) {
	if (numFriends == 1) return word;
	std::vector<int> sa = buildSA(word);
	int n = word.size();
	size_t len = std::min(n - sa[n], n - numFriends + 1);
	std::string ans = word.substr(sa[n], len);
	return ans;
}
int main()
{
	std::cout << f("dbca", 2) << std::endl;
	std::cout << f("gggg", 4) << std::endl;
	std::cout << f("acigheigadqna", 3) << std::endl;
	std::cout << f("gh", 1) << std::endl;
	return 0;
}
// runtime beats 91.42%
// memory beats 85.45%
