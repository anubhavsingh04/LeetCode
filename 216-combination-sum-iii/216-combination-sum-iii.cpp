class Solution {
public:
    vector<vector<int>>res;
    vector<int>ans;
    void solve(int n,int k,int num,int sum,vector<int>&v,vector<vector<int>>&ans)
    {
        if(v.size()>k || sum>n) return;
        if(sum==n && v.size()==k)
        {
            ans.push_back(v);
            return;
        }
        for(int i=num;i<=9;i++)
        {
            v.push_back(i);
            solve(n,k,i+1,sum+i,v,ans);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        int sum=0;
        int num=1;
        vector<vector<int>>ans;
        vector<int>v;
        solve(n,k,num,sum,v,ans);
        return ans;
    }
};