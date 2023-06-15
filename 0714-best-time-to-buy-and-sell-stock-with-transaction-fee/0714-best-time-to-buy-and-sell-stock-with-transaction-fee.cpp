class Solution {
public:
    int rec(int i,int buy,vector<int>&prices,int fee,vector<vector<int>>&dp)
    {
        if(i>=prices.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy==1){
            return dp[i][buy]=max(-prices[i]+rec(i+1,0,prices,fee,dp),rec(i+1,1,prices,fee,dp));
        }
        else {
            return dp[i][buy]=max(prices[i]-fee+rec(i+1,1,prices,fee,dp),rec(i+1,0,prices,fee,dp));
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return rec(0,1,prices,fee,dp);
    }
};