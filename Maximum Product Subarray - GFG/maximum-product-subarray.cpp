//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	// if the count of negative number is odd then we have to either exclude first or last one 
	// we can do this in two pass 
	// if zero occours then update currpdt to 1
	long long maxProduct(vector<int> nums, int n) {
	    long long ans=INT_MIN,left_pdt=1,right_pdt=1;
	    for(int i=0;i<n;i++)
	    {
	        left_pdt*=nums[i];
	        right_pdt*=nums[n-i-1];
	        ans=max(ans,max(left_pdt,right_pdt));
	        if(left_pdt==0) left_pdt=1;
	        if(right_pdt==0) right_pdt=1;
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends