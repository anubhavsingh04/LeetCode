// 1st row with 1e9 or intmax-1 colfrom 1 to n+1 with 0 because we have no way to make o amount with no of coins>0 
// second row if(j%arr[0]==0) then j/arr[0] else 1e9

class Solution {
public:
    int coinChange(vector<int>& coins, int target) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(target+1,0));
// first row with intmax as there are infinite set required to make sum if no of elements in the array is 0  
	    
	    for(int j=0;j<target+1;j++) 
	    {
	        dp[0][j]=1e9;
	    }
	    for(int j=1;j<target+1;j++) 
	    {
	        if(j%coins[0]==0)
	        dp[1][j]=j/coins[0];
	        else 
	        dp[1][j]=1e9;
	    }
	    for(int i=2;i<n+1;i++)
	    {
	        for(int j=1;j<target+1;j++)
	        {
	            if(coins[i-1]<=j)
	            dp[i][j]=min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
	            else 
	            dp[i][j]=dp[i-1][j];
	        }
	    }
	    if(dp[n][target]==1e9) return -1;
	    else return dp[n][target];
    }
};