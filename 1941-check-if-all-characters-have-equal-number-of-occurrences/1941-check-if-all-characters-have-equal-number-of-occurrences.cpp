class Solution {
public:
    bool areOccurrencesEqual(string s) {
        map<char,int>m;
        for(auto &i:s)
        {
            m[i]++;
        }
        int cnt=m[s[0]];
        for(auto &i:m)
        {
            if(m[i.first]!=cnt)
                return false;
        }
        return true;
    }
};