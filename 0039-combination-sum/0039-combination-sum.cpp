class Solution {
public:
    void rec(int sum,int idx,vector<int>&nums,int target,vector<int>op,vector<vector<int>>&ans)
    {
        if(sum>target) return ;
        if(sum==target){
            ans.push_back(op);
            return;
        }
        for(int i=idx;i<nums.size();i++)
        {
            sum+=nums[i];
            op.push_back(nums[i]);
            rec(sum,i,nums,target,op,ans);
            sum-=nums[i];
            op.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>op;
        rec(0,0,candidates,target,op,ans);
        return ans;
    }
};