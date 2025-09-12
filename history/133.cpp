#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<Node*, Node*> visited;
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return node;

        if (visited.find(node) != visited.end()) return visited[node];

        Node* clone = new Node(node->val);
        visited[node] = clone;

        for (auto& neighbor: node->neighbors) {
            clone->neighbors.emplace_back(cloneGraph(neighbor));
        }
        return clone;
    }
};

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 53.72%
