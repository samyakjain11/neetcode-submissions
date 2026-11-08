class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // so we effectievely want to backtrack and get a full list 
        std::vector<std::vector<int>> allPossibleSubsets;
        std::vector<int> currentVec;
        std::size_t index = 0;
        backtrack(nums, index, currentVec, allPossibleSubsets);
        return allPossibleSubsets;
    }
private:
    void backtrack(const std::vector<int>& nums, std::size_t index, std::vector<int>& currentVector, std::vector<std::vector<int>>& finalAnswer) {
        // we should only add to finalAnswer once we are at the final index or we are at finalIndex == nums.size(); lets use that as our base case
        if (index == nums.size()) {
            finalAnswer.emplace_back(currentVector);
            return;
        }

        // two choices, take or skip
        // take 
        currentVector.emplace_back(nums[index]);
        backtrack(nums, index + 1, currentVector, finalAnswer);
        // skip
        currentVector.pop_back();
        backtrack(nums, index + 1, currentVector, finalAnswer);
    }
};
