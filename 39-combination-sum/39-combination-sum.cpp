class Solution {
public:
    void findcombination(vector<int>& nums,int idx,int target,vector<int>&v,vector<vector<int>>&ans)
    {
        if(idx==nums.size())
        {
            if(target==0)
            {
                ans.push_back(v);
            }
            return;
        }
        // pick (if(nums[idx]<=target))
        if(nums[idx]<=target)
        {
            v.push_back(nums[idx]);
            findcombination(nums,idx,target-nums[idx],v,ans);
            v.pop_back(); // backtrack
        }
        // not pick 
        findcombination(nums,idx+1,target,v,ans);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>v;
        findcombination(candidates,0,target,v,ans);
        return ans;
    }
};