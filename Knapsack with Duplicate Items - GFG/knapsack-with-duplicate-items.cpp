//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int rec(int idx,int W,int *val,int *wt,vector<vector<int>>&dp)
    {
        if(idx==0)
        {
            return (W/wt[0])*val[0];
        }
        if(dp[idx][W]!=-1) return dp[idx][W];
        int notpick=rec(idx-1,W,val,wt,dp);
        int pick=-1e9;
        if(wt[idx]<=W){
            pick=val[idx]+rec(idx,W-wt[idx],val,wt,dp);
        }
        return dp[idx][W]=max(pick,notpick);
    }
    int knapSack(int n, int W, int val[], int wt[])
    {
        vector<vector<int>>dp(n,vector<int>(W+1,-1));
        return rec(n-1,W,val,wt,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends