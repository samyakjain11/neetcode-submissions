class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> frequentElems;
        priority_queue<pair<unsigned int, int>> pairHeap; // {frequency, intNum}
        unordered_map<int, unsigned int> frequencyMap;
        for (unsigned int i = 0; i < nums.size(); ++i) {
            frequencyMap[nums[i]]++;
        }

        for (auto& [num, frequency] : frequencyMap) {
            pairHeap.push({frequency, num});
        }

        for (unsigned int i = 0; i < k; ++i) {
            frequentElems.emplace_back(pairHeap.top().second);
            pairHeap.pop();
        }

        return frequentElems;
    }
};
