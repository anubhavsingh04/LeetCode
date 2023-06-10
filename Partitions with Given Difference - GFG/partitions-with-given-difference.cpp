//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
   const int mod=1e9+7;
    int countPartitions(int n, int d, vector<int>& arr) {
        int total=accumulate(arr.begin(),arr.end(),0);
        if((total-d)<0 || (total-d)%2==1) return 0;
        int sum=(total-d)/2;
        
        vector<vector<int>>dp(n,vector<int>(sum+1,0));
        for(int i=0;i<n;i++) dp[i][0]=1;
        
        if(arr[0]!=0 && arr[0]<=sum) dp[0][arr[0]]=1;
        
        if(arr[0]==0) dp[0][0]=2;
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                int notpick=dp[i-1][j];
                int pick=0;
                if(arr[i]<=j) pick=dp[i-1][j-arr[i]];
                dp[i][j]=(pick+notpick)%mod;
            }
        }
        return dp[n-1][sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends