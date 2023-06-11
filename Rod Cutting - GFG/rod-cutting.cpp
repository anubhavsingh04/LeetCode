//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    
    int cutRod(int price[], int n) {
        vector<vector<int>>dp(n,vector<int>(n+1,0));
        for(int j=0;j<=n;j++) dp[0][j]=j*price[0];
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=n;j++) // for rod length 
            {
                int notpick=dp[i-1][j];
                int pick=-1e9;
                int rodlen=i+1;
                if(j>=rodlen) // length badi honi chahiye cuttling lenth se tabhi kat payenge
                {
                    pick=price[i]+dp[i][j-rodlen];
                }
                dp[i][j]=max(pick,notpick);
            }
        }
        return  dp[n-1][n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends