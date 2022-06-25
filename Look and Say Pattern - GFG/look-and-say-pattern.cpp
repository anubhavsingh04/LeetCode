// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    string lookandsay(int n) {
        return solve(n,"1");
    }   
    string solve(int n,string s)
    {
        if(n==1)
        return  s;
        int i=0,j;
        string ans;
        while(i<s.size())
        {
            j=i;
            while(i<s.size() &&s[i]==s[j])
            i++;
            ans+=to_string(i-j)+s[j];
        }
        return solve(n-1,ans);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution obj;
        cout<<obj.lookandsay(n)<<endl;
    }
    return 0;
}  // } Driver Code Ends