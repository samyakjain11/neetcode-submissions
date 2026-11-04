class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<std::vector<int>> allPossibleSubsets;
        const int maxSize = 1 << nums.size();
        allPossibleSubsets.reserve(maxSize);

        std::vector<int> current;
        backtrack(nums, 0, current, allPossibleSubsets);
        return allPossibleSubsets;
    }

private:
    void backtrack(std::vector<int>& nums, size_t start, std::vector<int> current, std::vector<std::vector<int>>& allPossibleSubsets) {
        if (start == nums.size()) {
            allPossibleSubsets.push_back(current);
            return;
        }

        // choosing to not include
        backtrack(nums, start + 1, current, allPossibleSubsets);
        current.push_back(nums[start]);
        // after choosing
        backtrack(nums, start + 1, current, allPossibleSubsets);

    }
};
