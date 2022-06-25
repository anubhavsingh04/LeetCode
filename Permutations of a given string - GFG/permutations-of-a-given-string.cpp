// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	void solve(string &s,set<string>&st,int idx)
	{
	    if(idx >= s.length())
	    {
	        st.insert(s);
	        return;
	    }
	    for(int j=idx;j<s.size();j++)
	    {
	        swap(s[j],s[idx]);
	        solve(s,st,idx+1);
	        swap(s[j],s[idx]);
	    }
	}
		vector<string>find_permutation(string S)
		{
		    int idx=0;
		    set<string>st;
		  vector<string>v;
		    solve(S,st,idx);
		    for(auto &i:st)
		    {
		        v.push_back(i);
		    }
		    return v;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends