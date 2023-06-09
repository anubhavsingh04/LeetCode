class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            dp[0][j]=grid[0][j];
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int ld=1e9,rd=1e9;
                int up=grid[i][j]+dp[i-1][j];
                if(j-1>=0)ld=grid[i][j]+dp[i-1][j-1];
                if(j+1<m)rd=grid[i][j]+dp[i-1][j+1];
                dp[i][j]=min({up,ld,rd});
            }
        }
        int ans=INT_MAX;
        for(int j=0;j<m;j++)
        {
            ans=min(ans,dp[n-1][j]);
        }
        return ans;
    }
};

