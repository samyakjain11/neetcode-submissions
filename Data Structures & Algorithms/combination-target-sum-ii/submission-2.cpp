class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::vector<std::vector<int>> fittingCandidates;
        std::vector<int> currentCandidates;
        int currentSum = 0;
        std::size_t currentIdx = 0;

        std::sort(candidates.begin(), candidates.end());

        backtrack(candidates, currentCandidates, target, currentSum, currentIdx, fittingCandidates);
        return fittingCandidates;
    }

private:
    void backtrack(const vector<int>& candidates, 
                    std::vector<int>& current, 
                    int target, 
                    int curSum, 
                    std::size_t curIndex, 
                    std::vector<std::vector<int>>& fittingCandidates) {
        
        if (curSum == target) {
            fittingCandidates.push_back(current);
            return;
        }

        if (curSum > target || curIndex >= candidates.size()) {
            return;
        }

        // take
        current.push_back(candidates[curIndex]);
        backtrack(candidates, current, target, curSum + candidates[curIndex], curIndex + 1, fittingCandidates);
        // skip, we must now also skip ALL of the next numbers that are the same
        current.pop_back();

        std::size_t next = curIndex + 1;
        while (next < candidates.size() && candidates[next] == candidates[curIndex]) {
            ++next;
        }
        backtrack(candidates, current, target, curSum, next, fittingCandidates);
    }
};
