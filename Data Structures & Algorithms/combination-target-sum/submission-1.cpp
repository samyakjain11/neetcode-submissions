class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        std::vector<std::vector<int>> allPossibleCombinations;
        // allPossibleCombinations.reserve(1 << nums.size());
        std::vector<int> currentCombination;
        unsigned int index = 0;
        int currentSum = 0;
        backtrack(nums, index, currentCombination, currentSum, target, allPossibleCombinations);
        return allPossibleCombinations;
    }

private:
    void backtrack(std::vector<int>& nums, 
                    unsigned int index, 
                    std::vector<int>& current, 
                    int currentSum,
                    int target,
                    std::vector<std::vector<int>>& allPossibleCombinations) {

        if (currentSum > target) {
            return;
        }

        if (currentSum == target) {
            allPossibleCombinations.push_back(current);
            return;
        }

        if (index >= nums.size()) {
            return;
        }
        // take
        current.push_back(nums[index]);
        backtrack(nums, index, current, currentSum + nums[index], target, allPossibleCombinations);

        // skip
        current.pop_back();
        backtrack(nums, index + 1, current, currentSum, target, allPossibleCombinations);
        

    }
};
