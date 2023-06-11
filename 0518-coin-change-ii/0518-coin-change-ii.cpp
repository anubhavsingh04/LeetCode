class Solution {
public:
    int rec(int idx,int amount,vector<int>&coins,vector<vector<int>>&dp)
    {
        if(idx==0) return amount%coins[0]==0;
        
        if(dp[idx][amount]!=-1) return dp[idx][amount];
        int notpick=rec(idx-1,amount,coins,dp);
        int pick=0;
        if(coins[idx]<=amount)
        {
            pick=rec(idx,amount-coins[idx],coins,dp);
        }
        return dp[idx][amount]=(pick+notpick);
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return rec(n-1,amount,coins,dp);
    }
};