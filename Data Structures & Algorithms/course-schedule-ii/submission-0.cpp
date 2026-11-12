class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // thinking of a graph representation
        // topological sort on the courses that we need to take
        // kahns algorithm -> indegree tracker, queue 
        vector<vector<int>> adjList(numCourses);
        vector<int> inDegree(numCourses);
        
        for (const auto& edge : prerequisites) {
            const int from = edge[1];
            const int to   = edge[0];
            adjList[from].push_back(to);
            ++inDegree[to];
        }

        queue<int> pendingTraversal;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                pendingTraversal.push(i);
            }
        }

        vector<int> traversalOrder;
        traversalOrder.reserve(numCourses);

        while (!pendingTraversal.empty()) {
            const int currNode = pendingTraversal.front();
            pendingTraversal.pop();
            for (const int neighbor : adjList[currNode]) {
                if(--inDegree[neighbor] == 0) {
                    pendingTraversal.push(neighbor);
                }
            }

            traversalOrder.push_back(currNode);
        }

        if(traversalOrder.size() != numCourses) {
            return {};
        } else {
            return traversalOrder;
        }


    }
};
