class Solution {
public:
    vector<vector<int>>dp;
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        dp.resize(n,vector<int>(m,1e9));
        int ans=1e9;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
               if(i==0) {
                   dp[i][j]= mat[i][j];
                   continue;
               }
                int up=1e9,left=1e9,right=1e9;
                if(j-1>=0)left=dp[i-1][j-1];
                if(j+1<m)right=dp[i-1][j+1];
                up=dp[i-1][j];
                dp[i][j]=mat[i][j]+min({left,up,right});
            }
        }
        for(int j=0;j<m;j++)
        {
            ans=min(ans,dp[n-1][j]);
        }
        return ans;
    }
};
