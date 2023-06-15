class Solution {
public:
    int rec(int i,int buy,vector<int>&prices,vector<vector<int>>&dp)
    {
        if(i>=prices.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy)
        {
            return dp[i][buy]=max(-prices[i]+rec(i+1,0,prices,dp),rec(i+1,1,prices,dp));
        }
        else {
            return dp[i][buy]=max(prices[i]+rec(i+1,1,prices,dp),rec(i+1,0,prices,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size()+1,vector<int>(2,-1));
        return rec(0,1,prices,dp); //idx=0,buy=1
    }
};