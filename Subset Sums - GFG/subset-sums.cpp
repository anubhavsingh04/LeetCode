//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void rec(int i,vector<int>&nums,int sum,vector<int>&ans)
    {
        if(i>=nums.size()) {
            ans.push_back(sum);
            return ;
        }
        // not pick
        rec(i+1,nums,sum,ans);
        rec(i+1,nums,nums[i]+sum,ans);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        int sum=0;
        vector<int>ans;
         rec(0,arr,sum,ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends