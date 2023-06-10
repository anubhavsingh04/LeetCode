//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    int sum=0;
	    for(int i=0;i<n;i++) sum+=arr[i];
	    vector<vector<int>>dp(n,vector<int>(sum+1,0));
	    for(int i=0;i<n;i++) dp[i][0]=1;
	    if(arr[0]<=sum) dp[0][arr[0]]=1;
	    for(int i=1;i<n;i++)
	    {
	        for(int j=0;j<=sum;j++)
	        {
	            int notpick=dp[i-1][j];
	            int pick=0;
	            if(arr[i]<=j)pick=dp[i-1][j-arr[i]];
	            dp[i][j]=pick||notpick;
	        }
	    }
	    int ans=INT_MAX;
	    for(int j=0;j<sum/2+1;j++)
	    {
            if(dp[n-1][j]==1) ans=min(ans,abs(sum-j-j));
	    }
	    return ans;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends