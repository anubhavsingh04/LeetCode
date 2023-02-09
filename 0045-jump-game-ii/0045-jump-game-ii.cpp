class Solution {
public:
    long long rec(int curr, vector<int> &nums, int n,vector<int>&dp){
        if(curr>=n-1){
            return 0;
        }
        if(dp[curr]!=-1) return dp[curr];
        long long ans=INT_MAX;
        for(int i=curr+1; i<=curr+nums[curr]; i++){
            ans=min(ans, 1+rec(i,nums,n,dp));
        }
        return dp[curr]=ans;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        int curr=0;
        vector<int>dp(n+1,-1);
        return rec(0,nums,n,dp);
    }
};