// let say abc is the string /array take 
// swap a with a then a with b then a with c 
// after this we will get three string abc,bac,cba and index will be increased by one
// let say for string bac we are returning then we need to again swap b with a 
// so that abc will be returned and then further call for swapping of c will be done 
class Solution {
public:
    void solve(vector<int>nums,int idx,vector<vector<int>>&ans)
    {
        if(idx>=nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int j=idx;j<nums.size();j++)
        {
            swap(nums[j],nums[idx]);
            solve(nums,idx+1,ans);
            swap(nums[j],nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        int idx=0;
        solve(nums,idx,ans);
        return ans;
    }
};