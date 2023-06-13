//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    int rec(int idx1,int idx2,string s1,string s2,vector<vector<int>>&dp)
    {
        if(idx1<0 || idx2<0) return 0;
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        if(s1[idx1]==s2[idx2]) return dp[idx1][idx2]=1+rec(idx1-1,idx2-1,s1,s2,dp);
        else return dp[idx1][idx2]=max(rec(idx1-1,idx2,s1,s2,dp),rec(idx1,idx2-1,s1,s2,dp));
    }
    int lcs(int x, int y, string s1, string s2)
    {
        vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        return rec(s1.size()-1,s2.size()-1,s1,s2,dp);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends