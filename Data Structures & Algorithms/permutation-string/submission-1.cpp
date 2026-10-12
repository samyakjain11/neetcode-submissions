class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        std::unordered_map<char, int> lettersFreqMap, currentWindow;
        for (const char& c : s1) {
            ++lettersFreqMap[c];
        }

        for (size_t i = 0; i < s2.size(); ++i) {
            ++currentWindow[s2[i]];

            if (i >= s1.size()) {
                const char& charOut = s2[i - s1.size()];
                if (--currentWindow[charOut] == 0) currentWindow.erase(charOut);
            }

            if (currentWindow == lettersFreqMap) return true;
        }

        return false;

    }
};
