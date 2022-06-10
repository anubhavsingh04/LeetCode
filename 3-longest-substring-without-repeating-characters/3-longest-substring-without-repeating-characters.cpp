class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> v(256, -1);
        int start = -1, maxRes = 0;
        for(int i = 0; i < s.length(); i++) {
            start = max(start, v[s[i]]);
            v[s[i]] = i;
            maxRes = max(maxRes, i - start);
        }
        return maxRes;
    }
};