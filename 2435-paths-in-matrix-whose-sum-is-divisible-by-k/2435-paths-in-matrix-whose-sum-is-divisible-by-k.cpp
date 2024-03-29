class Solution {
public:
    #define MOD 1000000007
    int rec(int i,int j,int m,int n,int rem,vector<vector<int>>& grid,
            int k,vector<vector<vector<int>>>&dp)
    {
        if(i>=m || j>=n) return 0;
        if(i==m-1 && j==n-1)
        {
            if((grid[i][j]+rem)%k==0)
            {
                return 1;
            }
            return 0;
        }
        if(dp[i][j][rem]!=-1) return dp[i][j][rem];
        int nxt_rem=(grid[i][j]+rem)%k;
        int right=rec(i,j+1,m,n,nxt_rem,grid,k,dp);
        int down=rec(i+1,j,m,n,nxt_rem,grid,k,dp);
        return dp[i][j][rem]=(right+down)%MOD;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(k,-1)));
        return rec(0,0,m,n,0,grid,k,dp);
    }
};