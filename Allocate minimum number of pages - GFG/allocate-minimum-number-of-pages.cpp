//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool ispossible(int nums[],int n,int mid,int k)
    {
        int std=1,sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(sum>mid){
                std++;
                sum=nums[i];
            }
            if(std>k) return false;
        }
        return true;
    }
    int findPages(int nums[], int n, int k) 
    {
        if(n<k) return -1;
        int maxi=nums[0];
        int sum=0,ans;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,nums[i]);
            sum+=nums[i];
        }
        int start=maxi,end=sum;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(ispossible(nums,n,mid,k))
            {
                ans=mid;
                end=mid-1;
            }
            else {
                start=mid+1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends