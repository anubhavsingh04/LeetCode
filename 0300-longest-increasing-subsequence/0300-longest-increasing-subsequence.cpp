// dont forgrt to intialize pick and not pick as 0
// we can pick an element if prev==-1 or nums[curr]>nums[prev]
class Solution {
public:
    vector<vector<int>>dp;
    int LIS(vector<int>&nums,int prev,int curr)
    {
        if(curr>=nums.size()) return 0;
        if(dp[prev+1][curr]!=-1) return dp[prev+1][curr];
        int pick=0,notpick=0;
        if(prev==-1||nums[curr]>nums[prev]){
            pick=1+LIS(nums,curr,curr+1);
        }
        notpick=LIS(nums,prev,curr+1);
        return dp[prev+1][curr]=max(pick,notpick);
    }
    int lengthOfLIS(vector<int>& nums) {
        int curr=0,prev=-1;
        int n=nums.size();
        dp.resize(n+1,vector<int>(n+1,-1));
        return LIS(nums,prev,curr);
    }
};