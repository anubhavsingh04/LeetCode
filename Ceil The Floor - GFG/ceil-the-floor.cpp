//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends

int b_search(int *arr,int n,int x,string s)
{
    int start=0,end=n-1;
    int ans=-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]==x) return x;
        else if(arr[mid]<x)
        {
            if(s=="floor")
            {
                ans=arr[mid];
            }
            start=mid+1;
        }
        else 
        {
            if(s=="ceil")
            ans=arr[mid];
            end=mid-1;
        }
    }
    return ans;
}

pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    pair<int,int>ans;
    sort(arr,arr+n);
    ans.first=b_search(arr,n,x,"floor");
    ans.second=b_search(arr,n,x,"ceil");
    return ans;
}