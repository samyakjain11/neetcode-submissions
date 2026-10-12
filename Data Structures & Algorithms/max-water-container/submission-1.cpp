class Solution {
public:
    int maxArea(vector<int>& heights) {
        size_t left = 0, right = heights.size() - 1;
        
        auto computeArea = [&]() -> int {
            const int windowSize = right - left;
            return windowSize * std::min(heights[left], heights[right]);
        };
        int maxAreaSeenSoFar = computeArea();

        while (left < right) {
            maxAreaSeenSoFar = max(maxAreaSeenSoFar, computeArea());
            if (heights[left] < heights[right]) {
                ++left;
            } else {
                --right;
            }
        }

        return maxAreaSeenSoFar;
    }
};
