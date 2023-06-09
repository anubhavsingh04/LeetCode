class Solution {
public:
    int rec(int i,int j,int n,vector<vector<int>>&triangle,vector<vector<int>>&dp){
        if(i==n-1) {
            return triangle[i][j];
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int down=triangle[i][j]+rec(i+1,j,n,triangle,dp);
        int diagonal=triangle[i][j]+rec(i+1,j+1,n,triangle,dp);
        return dp[i][j]=min(down,diagonal);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j>=0;j--)
            {
                if(i==n-1) {
                    dp[i][j]=triangle[i][j];
                    continue;
                }
                int down=triangle[i][j]+dp[i+1][j];
                int diagonal=triangle[i][j]+dp[i+1][j+1];
                dp[i][j]=min(down,diagonal);
            }
        }
        return dp[0][0];
    }
};