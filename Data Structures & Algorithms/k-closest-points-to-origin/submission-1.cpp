class Solution {
public:
    using distPointPair = std::pair<int, std::pair<int, int>>;

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // can defintiely write a lambda function for this
        // we just need to sort by two points
        std::priority_queue<distPointPair, vector<distPointPair>> distancePointHeap;
        for (const auto& p : points) {
            const int x = p[0]; const int y = p[1];
            distancePointHeap.push({x*x + y*y, {x, y}});
            if (distancePointHeap.size() > k) {
                distancePointHeap.pop();
            }
        }
        
        std::vector<std::vector<int>> result;
        result.reserve(k);
        while (distancePointHeap.size() != 0) {
            const auto& [x,y] = distancePointHeap.top().second;
            result.push_back({x, y});
            distancePointHeap.pop();
        }
        return result;
    }
};
