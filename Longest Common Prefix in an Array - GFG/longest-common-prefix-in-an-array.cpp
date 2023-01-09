//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string str[], int n)
    {
        sort(str,str+n);
        string a=str[0],b=str[n-1];
        string ans="";
        for(int i=0;i<a.size();i++)
        {
            if(a[i]==b[i]) ans+=a[i];
            else break;
        }
        return ans!=""?ans:"-1";
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends