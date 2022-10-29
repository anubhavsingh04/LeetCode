class Solution {
public:
    int recur(vector<vector<char>>& mat,int i,int j,int n,int m,int &ans,vector<vector<int>>&dp)
    {
        if(i<0||i>=n||j<0||j>=m||mat[i][j]=='0')
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
       return dp[i][j]=1+min({recur(mat,i,j+1,n,m,ans,dp),recur(mat,i+1,j,n,m,ans,dp),recur(mat,i+1,j+1,n,m,ans,dp)});
    }
    int maximalSquare(vector<vector<char>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int ans=0;
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
     
        int side=0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(mat[i-1][j-1] == '1')
                {
                
                   dp[i][j]=1+min({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]});
                    side=max(side,dp[i][j]);
                }
                else
                    dp[i][j]=0;
            }
        }
        return side*side;
    }
};