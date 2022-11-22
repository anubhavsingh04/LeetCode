class Solution {
public:
    int rec(int n,vector<int>&dp)
    {
        if(n==0) return 0;
        if(dp[n]!=-1) return dp[n];
        dp[n]=INT_MAX;
        for(int i=1;i*i<=n;i++)
        {
            dp[n]=min(dp[n],1+rec(n-(i*i),dp));
        }
        return dp[n];
    }
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        return rec(n,dp);
    }
};