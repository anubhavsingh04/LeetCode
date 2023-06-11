class Solution {
public:
    int rec(int i,vector<int>&nums,int target,vector<vector<int>>&dp)
    {
        if(i==0) {
            if(nums[0]==0 && target==0) return 2;
            if(target==0 || nums[0]==target) return 1;
            return 0;
        }
        if(dp[i][target]!=-1)return dp[i][target];
        int notpick=rec(i-1,nums,target,dp);
        int pick=0;
        if(nums[i]<=target){
            pick=rec(i-1,nums,target-nums[i],dp);
        }
        return dp[i][target]=pick+notpick;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        target=abs(target);
        int total=accumulate(nums.begin(),nums.end(),0);
        if(total+target<0||(total+target)%2==1) return 0;
        target=(total+target)/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return rec(n-1,nums,target,dp);
    }
};