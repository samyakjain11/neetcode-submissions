class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0 || s.length() == 1) return s.length();
        unsigned int maxLength = 0;
        unordered_map<char, unsigned int> charLastSeenIndex;
        unsigned int startIndex = 0;
        charLastSeenIndex.insert({s[startIndex], startIndex});

        for(unsigned int endIndex = 1; endIndex < s.length(); endIndex++){
            if (charLastSeenIndex.count(s[endIndex]) && charLastSeenIndex[s[endIndex]] >= startIndex) {
                startIndex = charLastSeenIndex[s[endIndex]] + 1;
            }
            maxLength = max(maxLength, endIndex - startIndex + 1);
            charLastSeenIndex.insert_or_assign(s[endIndex], endIndex);
        }
        
        return maxLength;
    }
};
