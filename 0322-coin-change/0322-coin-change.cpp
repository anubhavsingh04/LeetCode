class Solution {
public:
    int coinChange(vector<int>& coins, int target) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(target+1,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=target;j++)
            {
                if(i==0){ // base case 
                    if(j%coins[0]==0) dp[0][j]=j/coins[0];
                    else dp[0][j]=1e9;
                    continue;
                }
                int notpick=dp[i-1][j];
                int pick=1e9;
                if(coins[i]<=j)
                {
                    pick=1+dp[i][j-coins[i]];
                }
                dp[i][j]=min(pick,notpick);
            }
        }
        int ans=dp[n-1][target];
        if(ans>=1e9) return -1;
        else return ans;
    }
};