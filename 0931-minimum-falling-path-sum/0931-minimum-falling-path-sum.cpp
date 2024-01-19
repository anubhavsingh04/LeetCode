// class Solution {
// public:
//     vector<vector<int>>dp;
//     int rec(int i,int j,vector<vector<int>>&mat)
//     {
//         if(j<0||j>=mat[0].size()) return 1e9;
//         if(i==mat.size()-1) return mat[i][j];
//         if(dp[i][j]!=-1) return dp[i][j];
//         int down=mat[i][j]+rec(i+1,j,mat);
//         int left=mat[i][j]+rec(i+1,j-1,mat);
//         int right=mat[i][j]+rec(i+1,j+1,mat);
//         return dp[i][j]=min({left,down,right});
//     }
//     int minFallingPathSum(vector<vector<int>>& mat) {
//         int n=mat.size();
//         int m=mat[0].size();
//         dp.resize(n+1,vector<int>(m+1,0));
//         int ans=1e9;
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                if(i==n-1) {
//                    dp[i][j]= mat[i][j];
//                    continue;
//                }
//                 int down=1e9,left=1e9,right=1e9;
//                 if(i+1<n)down=mat[i][j]+dp[i+1][j];
//                 if(i+1<n && j-1>=0) left=mat[i][j]+dp[i+1][j-1];
//                 if(i+1<n && j-1>=0) right=mat[i][j]+dp[i+1][j+1];
//                 dp[i][j]=min({left,down,right});
//             }
//         }
//         for(int j=0;j<m;j++)
//         {
//             ans=min(ans,dp[n-1][j]);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<vector<int>>dp;
    int rec(int i,int j,vector<vector<int>>&mat)
    {
        if(j<0||j>=mat[0].size()) return 1e9;
        if(i==mat.size()-1) return mat[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int down=mat[i][j]+rec(i+1,j,mat);
        int left=mat[i][j]+rec(i+1,j-1,mat);
        int right=mat[i][j]+rec(i+1,j+1,mat);
        return dp[i][j]=min({left,down,right});
    }
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        dp.resize(n+2,vector<int>(m+2,1e9));
        int ans=1e9;
            for(int i=n-1;i>=0;i--)
            {
                for(int k=m-1;k>=0;k--)
                {
                        if(i==n-1) {
                       dp[i][k]= mat[i][k];
                       continue;
                    }
                    int down=1e9,left=1e9,right=1e9;
                    down=mat[i][k]+dp[i+1][k];
                    if(k-1>=0) left=mat[i][k]+dp[i+1][k-1];
                     right=mat[i][k]+dp[i+1][k+1];
                     dp[i][k]=min({left,down,right});
                }
            }
        
                for(int j=0;j<m;j++)
                {
                    ans=min(ans,dp[0][j]);
                }
        return ans;
    }
};