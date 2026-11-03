class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int, vector<int>, std::greater<int>> minHeapSizeK;
        for (const int num : nums) {
            minHeapSizeK.emplace(num);
            if (minHeapSizeK.size() > k) {
                minHeapSizeK.pop();
            }
        }

        return minHeapSizeK.top();

    }
};
