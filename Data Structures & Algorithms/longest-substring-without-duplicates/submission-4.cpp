class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0 || s.length() == 1) return s.length();
        
        int startIndex = 0;
        int maxLength = 0;

        unordered_set<char> seenInThisWindow;
        seenInThisWindow.insert(s[startIndex]);

        for (int endIndex = 1; endIndex < s.length(); endIndex++) {
            if (seenInThisWindow.count(s[endIndex])) {
                while (s[startIndex] != s[endIndex]) {
                    seenInThisWindow.erase(s[startIndex]);
                    startIndex++;
                }
                seenInThisWindow.erase(s[startIndex]);
                startIndex++;
            }
            seenInThisWindow.insert(s[endIndex]);
            maxLength = max(maxLength, endIndex - startIndex + 1);
        }

        return maxLength;
    }
};
