class Solution {
public:
    void solve(vector<int>&nums,vector<int>op,int idx,vector<vector<int>>&ans)
    {
        ans.push_back(op);
        for(int i=idx;i<nums.size();i++)
        {
            // if(i>idx && nums[i]==nums[i-1]) continue; 
            op.push_back(nums[i]);
            solve(nums,op,i+1,ans);
            op.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>op;
        solve(nums,op,0,ans);
        return ans;
    }
};