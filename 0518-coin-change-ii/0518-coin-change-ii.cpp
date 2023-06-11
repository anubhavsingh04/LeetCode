class Solution {
public:
    int change(int target, vector<int>& coins) {
       int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(target+1,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=target;j++)
            {
                if(i==0){ // base case 
                    if(j%coins[0]==0) dp[0][j]=1;
                    else dp[0][j]=0;
                    continue;
                }
                int notpick=dp[i-1][j];
                int pick=0;
                if(coins[i]<=j)
                {
                    pick=dp[i][j-coins[i]];
                }
                dp[i][j]=pick+notpick;
            }
        }
        return dp[n-1][target];
    }
};