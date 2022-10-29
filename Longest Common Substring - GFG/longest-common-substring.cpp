//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    // Memoization
    int rec(string &s1,string &s2,int m,int n,vector<vector<int>>&dp,int &ans)
    {
        if(n==0||m==0) return 0;
        if(dp[m][n]!=-1) return dp[m][n];
        int take=0;
        if(s1[m-1]==s2[n-1]) 
        {
            take=1+rec(s1,s2,m-1,n-1,dp,ans);
        }
    
        int l=rec(s1,s2,m,n-1,dp,ans);
        int r=rec(s1,s2,m-1,n,dp,ans);
        ans=max(ans,take);
        return dp[m][n]=take;
    }
    int longestCommonSubstr (string s1, string s2, int m, int n)
    {
        int ans=0;
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        rec(s1,s2,m,n,dp,ans);
        return ans;
    }
    
    
    //Tabulation (Top down)
    // int longestCommonSubstr (string s1, string s2, int n, int m)
    // {
    //     vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    //     int ans=0;
    //     for(int i=1;i<n+1;i++)
    //     {
    //         for(int j=1;j<m+1;j++)
    //         {
    //             if(s1[i-1]==s2[j-1])
    //             {
    //                 dp[i][j]=1+dp[i-1][j-1];
    //                 ans=max(ans,dp[i][j]);
    //             }
    //             else 
    //             dp[i][j]=0;
    //         }
    //     }
    //     return ans;
    // }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends