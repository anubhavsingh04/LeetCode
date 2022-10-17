class Solution {
public:
    bool checkIfPangram(string s) {
        unordered_set<char>st;
        for(auto &i:s)
        {
            st.insert(i);
        }
        return st.size()==26;
    }
};