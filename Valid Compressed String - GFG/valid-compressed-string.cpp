//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkCompressed(string s, string t) {
        int j=0,i=0;
        int n=s.size(),m=t.size();
        while(i<s.size() && j<t.size())
        {
            if(s[i]==t[j])
            {
                i++;
                j++;
            }
            else if(isdigit(t[j]))
            {
                int cnt=0;
                while(j<t.size() && isdigit(t[j]))
                {
                    cnt=(cnt*10+(t[j]-'0'));
                    j++;
                }
                i+=cnt;
                if(s[i]!=t[j]) return 0;
            }
        }
        if(i==n and j==m) return 1;
        return 0;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        
        cin>>S>>T;

        Solution ob;
        cout << ob.checkCompressed(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends