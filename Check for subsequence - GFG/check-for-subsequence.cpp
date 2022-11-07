//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std; 

// } Driver Code Ends

class Solution{
    public:
    bool isSubSequence(string A, string B) 
    {
        // int n=A.size();
        // int m=B.size();
        // vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        // for(int i=1;i<n+1;i++)
        // {
        //     for(int j=1;j<m+1;j++)
        //     {
        //         if(A[i-1]==B[j-1])
        //         {
        //             dp[i][j]=1+dp[i-1][j-1];
        //         }
        //         else 
        //         {
        //             dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        //         }
        //     }
        // }
        // return dp[n][m]==A.size();
        
        int i=0,j=0;
        while(i<A.size() && j<B.size())
        {
            if(A[i]==B[j])
            {
                i++;
                j++;
            }
            else 
            j++;
        }
        return i==A.size();
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    scanf("%d",&t);
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;  
        Solution ob;
        if(ob.isSubSequence(A,B))
            cout<<"1"<<endl;
        else
            cout<<"0"<<endl;
    }
    return 0; 
} 

// } Driver Code Ends