// swap with itsef or swap with next elements and increment the idx 
class Solution {
public:
    void permutation(int idx,vector<int>&nums,int n,vector<vector<int>>&ans)
    {
        if(idx==n-1){
            ans.push_back(nums);
            return;
        }
        for(int i=idx;i<n;i++)
        {
            swap(nums[idx],nums[i]);
            permutation(idx+1,nums,n,ans);
            swap(nums[idx],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        int idx=0;
        permutation(idx,nums,nums.size(),ans);
        return ans;
    }
};