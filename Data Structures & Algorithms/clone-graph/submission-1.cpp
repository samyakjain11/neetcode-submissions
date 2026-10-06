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
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        // we can do bfs or dfs, its just a little tricky cause we need to make sure we store the nodes correctly. maybe its easier to iterate the graph twice or somehow in a bottom top fashion 
        std::unordered_map<Node*, Node*> origToClonesMapping;
        return depthFirstSearch(node, origToClonesMapping);
    }

private:
    Node* depthFirstSearch(Node* original, std::unordered_map<Node*, Node*>& origToClonesMapping) {
        if (auto it = origToClonesMapping.find(original); it != origToClonesMapping.end()) {
            return it->second;
        } else {
            Node* newClone = new Node(original->val);
            origToClonesMapping[original] = newClone;

            newClone->neighbors.reserve(original->neighbors.size());
            for (auto* neighbor : original->neighbors) {
                newClone->neighbors.emplace_back(depthFirstSearch(neighbor, origToClonesMapping));
            }
            return newClone;
        }

    }
};
