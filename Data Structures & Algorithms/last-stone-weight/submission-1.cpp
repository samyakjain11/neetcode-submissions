class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        if (stones.size() == 0) return 0;
        if (stones.size() == 1) return stones[0];

        std::priority_queue<int> sortedStoneWeights(stones.begin(), stones.end());
        while (sortedStoneWeights.size() > 1) {
            const int biggerStoneWeight = sortedStoneWeights.top();
            sortedStoneWeights.pop();
            const int smallerStoneWeight = sortedStoneWeights.top();
            sortedStoneWeights.pop();
            const int difference = biggerStoneWeight - smallerStoneWeight;

            if (difference != 0) sortedStoneWeights.emplace(difference);
        }
        return sortedStoneWeights.size() == 0 ? 0 : sortedStoneWeights.top();
    }
};
