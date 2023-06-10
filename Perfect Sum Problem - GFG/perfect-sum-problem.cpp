//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	const int mod=1e9+7;
	int perfectSum(int arr[], int n, int sum)
	{
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
	            if(arr[i]<=j)pick=dp[i-1][j-arr[i]];
	            dp[i][j]=(pick+notpick)%mod;
	        }
	    }
	    return dp[n-1][sum];
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends