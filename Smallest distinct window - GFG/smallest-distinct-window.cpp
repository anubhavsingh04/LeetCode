//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string s)
    {
        unordered_set<char>st;
        for(auto &i:s)
        {
            st.insert(i);
        }
        string p="";
        for(auto &i:st)
        {
            p+=i;
        }
        
        
        unordered_map<char,int>m;
        for(auto &i:p)
        {
            m[i]++;
        }
        
        int i=0,j=0,n=s.size();
        int count=m.size();
        int ans=n;
        // int start=0;
        while(j<n)
        {
            if(m.find(s[j])!=m.end())
            {
                m[s[j]]--;
                if(m[s[j]]==0) count--;
            }
            if(count==0)
            {
                while(count==0)
                {
                    if(ans>j-i+1)
                    {
                        ans=j-i+1;
                        // start=i;
                    }
                    if(m.find(s[i])!=m.end())
                    {
                        m[s[i]]++;
                        if(m[s[i]]>0) count++;
                    }
                    i++;
                }
            }
            j++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends