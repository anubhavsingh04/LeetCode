//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    // we just have to count the maxm overlaps at any time (count method is used when any train arrives count ++ else counts --) 
    int findPlatform(int arr[], int dep[], int n)
    {
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	int i=0,j=0,count=0,ans=0;
    	while(i<n )
    	{
    	    if(arr[i]<=dep[j]) {
    	        i++;
    	        count++;
    	        ans=max(ans,count);
    	    }
    	    else if(arr[i]>dep[j])
    	    {
    	        j++;
    	        count--;
    	    }
    	}
    	return ans;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends