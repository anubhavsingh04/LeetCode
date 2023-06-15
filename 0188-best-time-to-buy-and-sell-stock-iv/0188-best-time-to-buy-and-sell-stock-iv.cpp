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
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return rec(0,1,k,prices,dp); 
        
    }
};