// unbounded knapsack
// dp[i][j]=dp[i][j-coins[i-1]] means we are picking the cirr coin but we can the same coin again 
// so  we are no decrementing i
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,0));
        for(int i=0;i<n+1;i++)
        {
            dp[i][0]=1;
        }
        for(int i=1;i<n+1;i++) // size 
        {
            for(int j=1;j<amount+1;j++) // amount 
            {
                if(coins[i-1]<=j) // pick or not pick
                {
                    dp[i][j]=(dp[i][j-coins[i-1]]+dp[i-1][j]); 
                }
                else
                    dp[i][j]=(dp[i-1][j]);
            }
        }
        return dp[n][amount];
    }
};