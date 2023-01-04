//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    vector<vector<int>>dp;
    vector<vector<int>>dp2;
    bool ispalindrome(string &s,int i,int j)
    {
        if(i>=j) return true;
        if(dp2[i][j]!=-1) return dp2[i][j];
        if(s[i]==s[j]) return dp2[i][j]=ispalindrome(s,i+1,j-1);
        return dp2[i][j]=false;
    }
    int solve(string s,int i,int j)
    {
        if(i>=j) return dp[i][j]=0;
        if(ispalindrome(s,i,j)) return dp[i][j]=0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MAX;
        for(int k=i;k<j;k++)
        {
            if(ispalindrome(s,i,k)){
                int tmpans=1+solve(s,k+1,j);
                ans=min(ans,tmpans);
            }
        } 
        return dp[i][j]=ans;
    }
    int palindromicPartition(string s)
    {
        int n=s.size();
        dp.resize(n+1,vector<int>(n+1,-1));
        dp2.resize(n+1,vector<int>(n+1,-1));
        return solve(s,0,n-1);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends