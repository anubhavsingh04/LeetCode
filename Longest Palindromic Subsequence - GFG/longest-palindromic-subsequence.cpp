//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  int LCS(string a,string b)
  {
      int m=a.size();
      int n=b.size();
      vector<vector<int>>dp(m+1,vector<int>(n+1,0));
      for(int i=1;i<m+1;i++)
      {
          for(int j=1;j<n+1;j++)
          {
              if(a[i-1]==b[j-1])
              dp[i][j]=1+dp[i-1][j-1];
              else 
              dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
          }
      }
      return dp[m][n];
  }
    int longestPalinSubseq(string A) {
        string s=A;
        reverse(s.begin(),s.end());
        return LCS(A,s);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends