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
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int max_area=0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(mat[i][j] == '1')
                {
                    int side = recur(mat,i,j,n,m,ans,dp);
                    int area = side * side;
                    max_area = max(max_area, area);
                }
            }
        }
        return max_area;
    }
};