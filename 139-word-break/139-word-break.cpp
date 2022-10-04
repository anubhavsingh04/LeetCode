class Solution {
public:
    int dfs(int idx,string s,set<string>&st,vector<int>& dp)
    {
        if(idx==s.size()) return 1;
        string tmp;
        if(dp[idx]!=-1) return dp[idx];
        
        for(int i=idx;i<s.size();i++)
        {
            tmp+=s[i];
            if(st.find(tmp)!=st.end())
            {
                if(dfs(i+1,s,st,dp)==1) return dp[idx]=1;
            }
        }
        return dp[idx]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string>st;
        int n=s.size();
        for(auto &i:wordDict)
        {
            st.insert(i);
        }
        int idx=0;
        vector<int>dp(n+1,-1);
        return dfs(idx,s,st,dp);
    }
};