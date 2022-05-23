class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size()<k) return false ;
       unordered_map<int,int>m;
        for(int i=0;i<s.size();i++)
        {
            m[s[i]]++;
        }
        int odd=0;
        for(auto x:m)
        {
            if(x.second%2==1) odd++;
        }
        return odd<=k;
    }
};