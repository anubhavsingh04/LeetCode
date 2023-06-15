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
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        for(int buy=0;buy<=1;buy++) dp[n][buy]=0;
        for(int i=n-1;i>=0;i--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                if(buy)
                {
                     dp[i][buy]=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                }
                else {
                     dp[i][buy]=max(prices[i]+dp[i+1][1],dp[i+1][0]);
                }
            }
        }
        return dp[0][1]; //idx=0,buy=1
    }
};