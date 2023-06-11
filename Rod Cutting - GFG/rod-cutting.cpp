//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int rec(int i,int *price,int len,vector<vector<int>>&dp)
    {
        if(i==0){
            return len*price[0];
        }
        if(dp[i][len]!=-1) return dp[i][len];
        int notpick=rec(i-1,price,len,dp);
        int pick=-1e9;
        int rodlen=i+1;
        if(len>=rodlen) // length badi honi chahiye cuttling lenth se tabhi kat payenge
        {
            pick=price[i]+rec(i,price,len-rodlen,dp);
        }
        return dp[i][len]=max(pick,notpick);
    }
    int cutRod(int price[], int n) {
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return rec(n-1,price,n,dp);
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