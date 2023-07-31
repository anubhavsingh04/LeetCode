//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int rec(int idx,int n,int k,vector<int>&nums,vector<int>&dp)
    {
        if(idx==n) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int sum=0,ans=-1e9,len=0,maxi=-1e9;
        for(int j=idx;j<min(n,idx+k);j++)
        {
            len++;
            maxi=max(maxi,nums[j]);
            sum=maxi*len+rec(j+1,n,k,nums,dp);
            ans=max(ans,sum);
        }
        return dp[idx]=ans;
    }
    int solve(int n, int k, vector<int>& nums){
        vector<int>dp(n+1,-1);
        return rec(0,n,k,nums,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            int x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        cout<<obj.solve(n,k,arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends