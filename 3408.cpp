#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

class TaskManager {
	std::set<array<int, 3>> st;
	std::unordered_map<int, std::pair<int, int>> mp;

	public:

	TaskManager(vector<vector<int>>& tasks) {
		for (auto &task : tasks) add(task[0], task[1], task[2]);
	}

	void add(int userId, int taskId, int priority) {
		st.insert({-priority, -taskId, userId});
		mp[taskId] = {userId, priority};
	}

	void rmv(int taskId) {
		auto p = mp[taskId];
		mp.erase(taskId);
		st.erase({-p.second, -taskId, p.first});
	}

	void edit(int taskId, int newPriority) {
		int user = mp[taskId].first;
		rmv(taskId);
		add(user, taskId, newPriority);
	}

	int execTop() {
		if (st.empty()) return -1;
		auto tri = *(st.begin());
		int ans = tri[2];
		rmv(-tri[1]);
		return ans;
	}
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats %
// memory beats %
