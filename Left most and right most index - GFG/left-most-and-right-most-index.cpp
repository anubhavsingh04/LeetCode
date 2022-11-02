//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    long long binarysearch(vector<long long >&v,int x,string occourence)
    {
        long long n=v.size();
        long long ans=-1;
        long long s=0,e=n-1;
        while(s<=e)
        {
            long long mid=s+(e-s)/2;
            if(v[mid]==x)
            {
                ans=mid;
                if(occourence=="first") // means first occourence chahiye
                e=mid-1;
                else s=mid+1;
            }
            else if(x<v[mid]) e=mid-1;
            else s=mid+1;
        }
        return ans;
    }
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        return {binarysearch(v,x,"first"),binarysearch(v,x,"last")};
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}

// } Driver Code Ends