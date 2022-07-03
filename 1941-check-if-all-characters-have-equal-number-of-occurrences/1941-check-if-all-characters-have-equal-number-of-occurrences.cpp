class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char,int>m;
        for(auto &i:s)
        {
            m[i]++;
        }
        int cnt=m[s[0]];
        for(auto &i:m)
        {
            if(m[i.first]!=cnt) // or i.second!=cnt is same as m[i.first]
                return false;
        }
        return true;
    }
};