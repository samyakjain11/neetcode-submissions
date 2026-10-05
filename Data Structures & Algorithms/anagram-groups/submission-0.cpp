class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> outputtedSublists;
        unordered_map<string, unsigned int> mapping;
        // how do we compare two sets??
        for(unsigned int i = 0; i < strs.size(); ++i) {
            string currentSortedString = strs[i];
            sort(currentSortedString.begin(), currentSortedString.end());
            if (!mapping.contains(currentSortedString)) {
                mapping[currentSortedString] = mapping.size();
                outputtedSublists.emplace_back();
            }
            unsigned int insertionPoint = mapping[currentSortedString];
            outputtedSublists[insertionPoint].emplace_back(strs[i]);
        }
        return outputtedSublists;
    }
};
