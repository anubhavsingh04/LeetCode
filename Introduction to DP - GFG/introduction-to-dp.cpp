//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
// fibona
vector<long long int>dp(100001 , 0);
class Solution {
  private:
    long long int topDownHelper(int n, long long int mod , vector<long long int>&dp){
        if(n<=1) return n;
        if(dp[n]!=-1) return dp[n];
        return dp[n] = (topDownHelper(n-1 , mod , dp ) + topDownHelper(n-2 , mod , dp))%mod;
    }
  public:
    long long int topDown(int n) {
        long long int mod = 1e9+7;
        vector<long long int>dp(n+1 , -1); 
        return topDownHelper(n , mod , dp);
    }

    long long int bottomUp(int n) {
         long long int mod = 1e9+7;
        vector<long long int>dp(n+1 , 0);
       dp[0] =0;
       dp[1] = 1;
        for(int i = 2 ; i <= n ; i++){
            dp[i] = (dp[i-1] + dp[i-2])%mod;
        }
        return dp[n]%mod;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    }
}
// } Driver Code Ends