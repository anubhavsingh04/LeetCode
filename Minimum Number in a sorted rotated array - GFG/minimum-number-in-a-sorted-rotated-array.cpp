//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the minimum element in sorted and rotated array.
    // min element hamesha unsorted part me hoga 
    int minNumber(int arr[], int start, int end)
    {
        int n=end-start+1;
        int ans;
        while(start<=end)
        {
            if(arr[start]<=arr[end]) return arr[start];
            
            int mid=start+(end-start)/2;
            int prev=(mid-1+n)%n;
            int next=(mid+1)%n;
            if(arr[mid]<=arr[prev] && arr[mid]<=arr[next]){
                ans=arr[mid];
                break;
            }
            else if(arr[start]<=arr[mid])
            {
                start=mid+1;
            }
            else 
            {
                end=mid-1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];	
		Solution obj;
		cout << obj.minNumber(a,0,n-1) << endl;
	}
	return 0;
}
// } Driver Code Ends