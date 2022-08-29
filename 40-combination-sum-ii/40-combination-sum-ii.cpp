class Solution {
public:
    void solve(vector<int>&nums,vector<int>op,int target,int idx,int sum,vector<vector<int>>&ans)
    {
        if(sum>target) return;
        if(sum==target){
            ans.push_back(op);
            return;
        }
        for(int i=idx;i<nums.size();i++)
        {
            if(i>idx && nums[i]==nums[i-1]) continue;
            if(nums[i]>target) break;
            op.push_back(nums[i]);
            sum+=nums[i];
            solve(nums,op,target,i+1,sum,ans);
            op.pop_back();
            sum-=nums[i];
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>op;
        solve(candidates,op,target,0,0,ans);
        return ans;
    }
};