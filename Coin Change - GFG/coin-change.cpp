//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int count(int coins[], int n, int amount) {
        vector<vector<long long>>dp(n+1,vector<long long>(amount+1,0));
        for(int i=0;i<n+1;i++) // if sum is 0 dont take any element so no of ways to make sum==0 is 1 by taking empty subset 
        {
            dp[i][0]=1;
        }
        for(int i=1;i<n+1;i++) // size 
        {
            for(int j=1;j<amount+1;j++) // amount 
            {
                if(coins[i-1]<=j) // pick or not pick
                {
                    dp[i][j]=(dp[i][j-coins[i-1]]+dp[i-1][j]); 
                }
                else
                    dp[i][j]=(dp[i-1][j]);
            }
        }
        return dp[n][amount];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends