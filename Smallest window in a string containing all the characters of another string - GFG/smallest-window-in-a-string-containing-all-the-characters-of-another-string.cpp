//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        unordered_map<char,int>m;
        for(auto &i:p)
        {
            m[i]++;
        }
        int count=m.size();
        int ans=INT_MAX,start=0;
        int i=0,j=0,n=s.size();
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
                        start=i;
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
        return ans!=INT_MAX?s.substr(start,ans):"-1";
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends