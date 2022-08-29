class Solution {
public:
    void solve(int n,int k,vector<int>op,int op_size,int idx,int sum,vector<vector<int>>&ans)
    {
        if(sum>n || op_size>k) return;
        if(sum==n && op_size==k){
            ans.push_back(op);
            return;
        }
        for(int i=idx;i<=9;i++)
        {
            op.push_back(i);
            sum+=i;
            solve(n,k,op,op_size+1,i+1,sum,ans);
            op.pop_back();
            sum-=i;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>op;
        solve(n,k,op,0,1,0,ans);
        return ans;
    }
};