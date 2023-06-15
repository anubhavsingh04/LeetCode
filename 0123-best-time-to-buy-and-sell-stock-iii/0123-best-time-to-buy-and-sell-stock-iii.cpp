class Solution {
public:
    int rec(int i,int buy,int trans,vector<int>&prices,vector<vector<vector<int>>>&dp)
    {
        if(trans<=0) return 0;
        if(i>=prices.size()) return 0;
        
        if(dp[i][buy][trans]!=-1) return dp[i][buy][trans];
        if(buy)
        {
            return dp[i][buy][trans]=max(-prices[i]+rec(i+1,0,trans,prices,dp),
                                         rec(i+1,1,trans,prices,dp));
        }
        else {
            return dp[i][buy][trans]=max(prices[i]+rec(i+1,1,trans-1,prices,dp),
                                         rec(i+1,0,trans,prices,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int trans=2;
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(trans+1,0)));
        for(int i=0;i<n;i++)
        {
            for(int buy=0;buy<=1;buy++)
            {
                dp[i][buy][0]=0;
            }
        }
        for(int buy=0;buy<=1;buy++)
        {
            for(trans=0;trans<2;trans++)
            {
                dp[n][buy][trans]=0;
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int trans=1;trans<=2;trans++)
                {
                    if(buy)
                    {
                        dp[i][buy][trans]=max(-prices[i]+dp[i+1][0][trans],
                                                     dp[i+1][1][trans]);
                    }
                    else {
                         dp[i][buy][trans]=max(prices[i]+dp[i+1][1][trans-1],
                                                     dp[i+1][0][trans]);
                    }
                }
            }
        }
        return dp[0][1][trans];
    }
};