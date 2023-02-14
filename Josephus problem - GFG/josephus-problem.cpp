//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
/*You are required to complete this method */

class Solution
{
    public:
    int rec(int idx,int k,vector<int>&v)
    {
        if(v.size()<=1) return v[0];
        idx=(idx+k)%v.size();
        v.erase(v.begin()+idx);
        return rec(idx,k,v);
    }
    int josephus(int n, int k)
    {
        vector<int>v;
        for(int i=1;i<=n;i++) v.push_back(i);
        k--;
        return rec(0,k,v);
    }
};



//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;//testcases
	while(t--)
	{
		int n,k;
		cin>>n>>k;//taking input n and k
		
		//calling josephus() function
		Solution ob;
		cout<<ob.josephus(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends