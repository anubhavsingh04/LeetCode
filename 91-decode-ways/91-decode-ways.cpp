class Solution {
public:
    vector<int>dp;
    int solve(int idx,string &s,vector<int>&dp)
    {
        if(dp[idx]!=-1) return dp[idx];
        if(idx==s.size()) return 1;
        if(s[idx]=='0') return 0;
        if(idx==s.size()-1) return 1;
        string tmp=s.substr(idx,2);
        int op1=solve(idx+1,s,dp);
        int op2=(stoi(tmp)>=1 && stoi(tmp)<=26)?solve(idx+2,s,dp):0;
        return dp[idx]=op1+op2;
    }
    int numDecodings(string s) {
        vector<int>dp(s.size()+1,-1);
         int ans=solve(0,s,dp);
        return ans;
        
    }
};