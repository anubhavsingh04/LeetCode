class Solution {
public:
    int rec(int idx,int target,vector<int>&coins,vector<vector<int>>&dp)
    {
        if(idx==0) {
            return target%coins[0]==0;
        }
        if(dp[idx][target]!=-1) return dp[idx][target];
        int nottake=rec(idx-1,target,coins,dp);
        int take=0;
        if(coins[idx]<=target) take=rec(idx,target-coins[idx],coins,dp);
        return  dp[idx][target]=take+nottake;
    }
    int change(int target, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return rec(n-1,target,coins,dp);
    }
};