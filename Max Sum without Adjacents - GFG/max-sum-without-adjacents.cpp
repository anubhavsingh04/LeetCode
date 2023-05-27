//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int rec(int idx,int *nums,int n,vector<int>&dp)
	{
	    if(idx>=n) return 0;
	    if(dp[idx]!=-1) return dp[idx];
	    int pick=nums[idx]+rec(idx+2,nums,n,dp);
	    int notpick=rec(idx+1,nums,n,dp);
	    return dp[idx]=max(pick,notpick);
	}
	int findMaxSum(int *arr, int n) {
	    int ans=INT_MIN;
	    vector<int>dp(n+1,-1);
	    return rec(0,arr,n,dp);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends