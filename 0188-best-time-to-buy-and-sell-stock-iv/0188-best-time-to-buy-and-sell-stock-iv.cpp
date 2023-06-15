class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        int trans=k;
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
            for(int trans=0;trans<=k;trans++)
            {
                dp[n][buy][trans]=0;
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int trans=1;trans<=k;trans++)
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