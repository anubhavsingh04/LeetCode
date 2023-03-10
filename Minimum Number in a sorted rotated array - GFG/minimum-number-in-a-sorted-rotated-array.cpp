//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    
    // same as rotation question
    
    //Function to find the minimum element in sorted and rotated array.
    // kitni bar rotate hua hai vo depend krenga minimum element ke index pe 
    // minimum element ka jo index hoga utni bar rotate hua hai
   // agr mid apne dono neighbour se chota hua to arr[mid] hi ans hoga 
   // nahi to min element hamesha unsoted array me lie krega 
   // so hame unsoted array me move krna hai
   // if a[start]<a[mid] means start to mid is sorted (do start=mid+1)
   // if a[mid]<a[end] means mid to end is sorted (do end=mid-11)
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