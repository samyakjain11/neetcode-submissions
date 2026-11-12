class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // mind jumps to graphs
        // detecting for cycles
        // topological sort?
        // we need to unpack our graph
        std::vector<std::vector<int>> adjList(numCourses);
        std::vector<int> inDegree(numCourses);

        for(const auto& edge : prerequisites) {
            const int to = edge[0];
            const int from = edge[1];
            ++inDegree[to];
            adjList[from].push_back(to);
        }

        // kahns algorithm, push every node with in degree 0 onto the queue
        // pop node, add to order, decrement neighbor. if neighbor== 0, add to queue
        std::queue<int> pendingTraversal;
        for(int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                pendingTraversal.push(i);
            }
        }

        int nodesTraversed = 0;

        while (!pendingTraversal.empty()) {
            int node = pendingTraversal.front();
            pendingTraversal.pop();

            for (const int& neighbor : adjList[node]) {
                if(--inDegree[neighbor] == 0) {
                    pendingTraversal.push(neighbor);
                }
            }
            ++nodesTraversed;
        }

        return nodesTraversed == numCourses;

    }
};
