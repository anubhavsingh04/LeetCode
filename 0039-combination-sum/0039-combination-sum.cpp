class Solution {
public:
    void rec(int sum,int idx,vector<int>&nums,int target,vector<int>op,vector<vector<int>>&ans)
    {
        if(sum>target||idx>=nums.size()) return;
        if(sum==target){
            ans.push_back(op);
            return;
        }
        // nottake
        rec(sum,idx+1,nums,target,op,ans);
        //take
        sum+=nums[idx];
        op.push_back(nums[idx]);
        rec(sum,idx,nums,target,op,ans);
        sum-=nums[idx];
        op.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>op;
        rec(0,0,candidates,target,op,ans);
        return ans;
    }
};