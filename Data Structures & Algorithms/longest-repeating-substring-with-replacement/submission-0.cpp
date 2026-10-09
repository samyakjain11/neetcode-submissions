class Solution {
public:
    int characterReplacement(string s, int k) {
        std::unordered_map<char, int> count;
        int maxFreq = 0;
        int best = 0;
        const int n = static_cast<int>(s.size());

        for (int l = 0, r = 0; r < n; ++r) {
            maxFreq = std::max(maxFreq, ++count[s[r]]);
            if (r - l + 1 - maxFreq > k) {
                --count[s[l++]];
            }
            best = std::max(best, r - l + 1);
        }
        return best;
    }
};