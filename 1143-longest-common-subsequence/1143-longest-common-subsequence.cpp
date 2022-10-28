// Recursion tLE
// class Solution {
// public:
//     int rec(string s1,string s2,int m,int n)
//     {
//         if(n==0||m==0)
//         {
//             return 0;
//         }
//         if(s1[m-1]==s2[n-1])
//         {
//             return 1+rec(s1,s2,m-1,n-1);
//         }
//         else 
//         {
//             return max(rec(s1,s2,m,n-1),rec(s1,s2,m-1,n));
//         }
//     }
//     int longestCommonSubsequence(string text1, string text2) {
//         int m=text1.size();
//         int n=text2.size();
//         return rec(text1,text2,m,n);
//     }
// };

// Memoization 
// class Solution {
// public:
//     int rec(string &s1,string &s2,int m,int n,vector<vector<int>>&dp)
//     {
//         if(n==0||m==0)
//         {
//             return 0;
//         }
//         if(dp[m][n]!=-1) return dp[m][n];
//         if(s1[m-1]==s2[n-1])
//         {
//             return dp[m][n]=1+rec(s1,s2,m-1,n-1,dp);
//         }
//         else 
//         {
//             return dp[m][n]=max(rec(s1,s2,m,n-1,dp),rec(s1,s2,m-1,n,dp));
//         }
//     }
//     int longestCommonSubsequence(string text1, string text2) {
//         int m=text1.size();
//         int n=text2.size();
//         vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
//         return rec(text1,text2,m,n,dp);
//     }
// };


class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int m=s1.size();
        int n=s2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<m+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                if(s1[i-1]==s2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
        return dp[m][n];
    }
};