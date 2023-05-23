class Solution {
public:
    void rec(int idx,vector<int>&nums,vector<int>op,vector<vector<int>>&ans)
    {
        ans.push_back(op);
        for(int i=idx;i<nums.size();i++)
        {
            if(i>idx && nums[i]==nums[i-1]) continue;
            op.push_back(nums[i]);
            rec(i+1,nums,op,ans);
            op.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>op;
        rec(0,nums,op,ans);
        return ans;
    }
};
