class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0){
                    dp[i][j]=grid[i][j];
                    continue;
                }
                int up=1e9,ld=1e9,rd=1e9;
                if(i-1>=0) up=grid[i][j]+dp[i-1][j];
                if(i-1>=0 && j-1>=0) ld=grid[i][j]+dp[i-1][j-1];
                if(i-1>=0 && j+1<m) rd=grid[i][j]+dp[i-1][j+1];
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

