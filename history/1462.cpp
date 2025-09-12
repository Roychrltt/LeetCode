#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pres, vector<vector<int>>& queries) {
        unordered_map<int, unordered_set<int>> required;

        for (auto& p : pres)
            required[p[1]].insert(p[0]);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (required[j].count(i))
                    required[j].insert(required[i].begin(), required[i].end());

        vector<bool> result;
        for (auto& query : queries)
            result.push_back(required[query[1]].count(query[0]) > 0);
        return result;
    }
};

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 58.18%
// memory beats 56.03%
