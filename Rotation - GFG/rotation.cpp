//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    // kitni bar rotate hua hai vo depend krenga minimum element ke index pe 
   // agr mid apne dono neighbour se chota hua to arr[mid] hi ans hoga 
   // nahi to min element hamesha unsoted array me lie krega 
   // so hame unsoted array me move krna hai
   // if a[start]<a[mid] means start to mid is sorted (do start=mid+1)
   // if a[mid]<a[end] means mid to end is sorted (do end=mid-11)
    int b_search(int arr[],int n)
    {
        int start=0,end=n-1;
        int ans=-1;
        while(start<=end)
        {
            int mid=(start+(end-start)/2);
            int prev=(mid-1+n)%n;
            int next=(mid+1)%n;
            
            if(arr[mid]<=arr[prev] && arr[mid]<=arr[end]) {
                ans=mid;
                break;
            }
            else if(arr[start]<=arr[mid]) { 
                start=mid+1;
            }
            else if(arr[mid]<=arr[end]) 
            {
                end=mid-1;
            }
        }
        return ans;
    }
	int findKRotation(int arr[], int n) {
	    if(arr[0]<=arr[n-1]) return 0;
	   // return b_search(arr,n);
	   int start=0,end=n-1;
        int ans=-1;
        while(start<=end)
        {
            int mid=(start+(end-start)/2);
            int prev=(mid-1+n)%n;
            int next=(mid+1)%n;
            // cout<<start<<" "<<mid<<" "<<end<<" "<<arr[mid]<<endl;
            
            if(arr[mid]<=arr[prev] && arr[mid]<=arr[next]) {
                ans=mid;
                break;
            }
            else if(arr[mid]>=arr[end]) { 
                start=mid+1;
            }
            else {
                end=mid-1;
            }
        }
        return ans;
        // int low=0,high=n-1,ans=-1;
        // // if(arr[0]<=arr[n-1]) return 0;
        // // if(arr[n-1]>=arr[0]) return n-1;
        // while(low<=high) {
        //     int mid=(low+high)>>1;
        //     if(mid>0 and mid<n-1 and arr[mid]<arr[mid-1] and arr[mid]<arr[mid+1]) return mid;
        //     else if(arr[mid]>arr[0]) {
        //         low=mid+1;
        //     }else {
        //         high=mid-1;
        //     }
        // }
        // return high;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends