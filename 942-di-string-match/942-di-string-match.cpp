class Solution {
public:
    vector<int> diStringMatch(string s) {
        int a=0,b=s.size();
        vector<int>ans;
        for(auto &i:s)
        {
            if(i=='I') ans.push_back(a++);
            else if(i=='D') ans.push_back(b--);
        }
        if(s[s.size()-1]=='D') ans.push_back(b--);
        if(s[s.size()-1]=='I') ans.push_back(a++);
        return ans;
    }
};