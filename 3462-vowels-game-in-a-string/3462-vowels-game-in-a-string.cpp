class Solution {
public:
    bool doesAliceWin(string s) {
        string vowels="aeiouAEIOU";
        unordered_set<char>st(vowels.begin(),vowels.end());
        for (char c : s) {
            if (st.count(c)) {
                return true;
            }
        }
        return false;
    }
};