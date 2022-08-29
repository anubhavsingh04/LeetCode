// Most optimal is using combinations
// we have to move int total of n-1 steps to right and m-1 steps to bottom
// if we can choose n-1 steps right out of m+n-2 then m-1 will be automatically placed 
// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         int N=m+n-2;
//         int r=n-1;
//         double ans=1;
//         for(int i=1;i<=r;i++)
//         {
//             ans=ans*(N-r+i)/i;
//         }
//         return (int)ans;
//     }
// };




class Solution {
public:
    int uniquePaths(int m, int n) {
       vector<vector<int>>dp(m,vector<int>(n,1));
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};



// Using dP
// class Solution {
// public:
//     int solve(int i,int j,int m,int n,vector<vector<int>>&dp)
//     {
//         if(i>=m || j>=n) return 0;
//         if(i==m-1 && j==n-1) return 1;
//         if(dp[i][j]!=-1) return dp[i][j];
//         return dp[i][j]=solve(i,j+1,m,n,dp)+solve(i+1,j,m,n,dp);
//     }
//     int uniquePaths(int m, int n) {
//         vector<vector<int>>dp(m,vector<int>(n,-1));
//         return solve(0,0,m,n,dp);
//     }
// };