class Solution {
public:
    int dfs(int i,int j,int m,int n,vector<vector<int>>&grid,vector<vector<int>>&dp)
    {
        if(i>=m || j>=n) return INT_MAX;
        if(i==m-1 && j==n-1)
        {
            return grid[i][j];
        }
        if(dp[i][j]!=-1) return dp[i][j];
        
        int l=dfs(i+1,j,m,n,grid,dp);
        int r=dfs(i,j+1,m,n,grid,dp);
        
        return dp[i][j]=grid[i][j]+min(l,r);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return dfs(0,0,m,n,grid,dp);
    }
};