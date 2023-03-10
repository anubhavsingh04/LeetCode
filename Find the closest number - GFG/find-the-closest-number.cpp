//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int findClosest(int arr[], int n, int target) 
    { 
        int start=0,end=n-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(arr[mid]==target) return target;
            else if(arr[mid]<target) start=mid+1;
            else end=mid-1;
        }
        if(end>=0 && start<n && abs(arr[start]-target)<abs(arr[end]-target)) return arr[start];
        else if(end>=0 && end<n && abs(arr[start]-target)>abs(arr[end]-target)) return arr[end];
        else return max(arr[start],arr[end]);
    } 
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,target;
        cin>>n>>target;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(arr,n,target)<<endl;
    }
}

// } Driver Code Ends