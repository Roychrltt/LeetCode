#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

class Solution {
    const std::array<int, 26> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};

    __int128 myGcd(__int128 a, __int128 b) {
        while (b != 0) {
            __int128 temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    __int128 getVal(const std::string& word) {
        __int128 ans = 1;
        for (char c : word)
            ans *= primes[c - 'a'];
        return ans;
    }
    __int128 myLcm(__int128 a, __int128 b) {
        return (a / myGcd(a, b)) * b;
    }
public:
    std::vector<std::string> wordSubsets(std::vector<std::string>& words1, std::vector<std::string>& words2) {
        std::vector<__int128> v;
        for (const auto& word : words1)
            v.push_back(getVal(word));

        __int128 mx = *std::max_element(v.begin(), v.end());

        __int128 bLCM = 1;
        for (const auto& word : words2) {
            __int128 val = getVal(word);
            bLCM = myLcm(bLCM, val);
            if (bLCM > mx) return {};
        }

        std::vector<std::string> ans;
        for (int i = 0; i < v.size(); ++i)
            if (v[i] % bLCM == 0)
                ans.push_back(words1[i]);

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
// runtime beats 76.26%
// memory beats 72.60%
