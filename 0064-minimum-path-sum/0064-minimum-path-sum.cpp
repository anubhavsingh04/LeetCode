class Solution {
public:
    int dfs(int n,int m,vector<vector<int>>&grid,vector<vector<int>>&dp)
    {
        if(n<0 || m<0) return 1e8;
        if(n==0 && m==0) return grid[n][m];
        if(dp[n][m]!=-1) return dp[n][m];
        int up=dfs(n-1,m,grid,dp);
        int left=dfs(n,m-1,grid,dp);
        return dp[n][m]=grid[n][m]+min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return dfs(n-1,m-1,grid,dp);
    }
};