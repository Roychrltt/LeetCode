#include <bits/stdc++.h>

class BIT{
	public:
		vector<int>bits;
		int min_num;
		int max_num;
		int n;

		BIT(int maxi,int mini)
		{
			min_num = mini;
			max_num = maxi;
			n = maxi - mini + 2;
			bits.resize(n);
		}
		void update(int i)
		{   
			i -= min_num;
			i++;
			while (i < n)
			{
				bits[i]++;
				i +=(i & (-i));
			}
		}
		int find(int i)
		{ 
			i -= min_num;
			int sum = 0;
			while(i > 0)
			{
				sum += bits[i];
				i -= (i & (-i));
			}
			return sum;
		}
};


class Solution {
	public:

		vector<int> countSmaller(vector<int>& nums) {
			vector<int> ans(nums.size());
			int mini = *min_element(nums.begin(),nums.end());
			int maxi = *max_element(nums.begin(),nums.end());

			BIT bitree(maxi, mini);

			for(int i = nums.size() - 1; i >= 0; i--){
				ans[i] = bitree.find(nums[i]);
				bitree.update(nums[i]);
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
// runtime beats 96.46%
// memory beats 96.37%
