class Solution {
public:
    void solve(vector<int>&nums,vector<int>op,int idx,vector<vector<int>>&ans)
    {
        if(idx==nums.size()){
            ans.push_back(op);
            return;
        }
        solve(nums,op,idx+1,ans);
        op.push_back(nums[idx]);
        solve(nums,op,idx+1,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>op;
        solve(nums,op,0,ans);
        return ans;
    }
};