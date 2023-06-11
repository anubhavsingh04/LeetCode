class Solution {
public:
    int rec(int idx,vector<int>&coins,int target,vector<vector<int>>&dp)
    {
        if(idx==0) {
            if(target%coins[0]==0) return target/coins[0];
            else return 1e9;
        }
        if(dp[idx][target]!=-1) return dp[idx][target];
        int notpick=rec(idx-1,coins,target,dp);
        int pick=1e9;
        if(coins[idx]<=target)
        {
            pick=1+rec(idx,coins,target-coins[idx],dp);
        }
        return dp[idx][target]=min(pick,notpick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans=rec(n-1,coins,amount,dp);
        if(ans>=1e9) return -1;
        else return ans;
    }
};