//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    vector<vector<int>>dp;
    int mcm(int n,int f) // total no of floors is f 
    {
        if(f==0||f==1) return f;
        if(n==1) return f;
        if(dp[n][f]!=-1) return dp[n][f];
        int ans=INT_MAX;
        for(int k=1;k<=f;k++) // dropping from kth floor either break or not break
        {
            int tmp=1+max(mcm(n-1,k-1),mcm(n,f-k));
            ans=min(ans,tmp);
        }
        return dp[n][f]=ans;
    }
    int eggDrop(int n, int k) 
    {
        dp.resize(n+1,vector<int>(k+1,-1));
        return mcm(n,k);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends