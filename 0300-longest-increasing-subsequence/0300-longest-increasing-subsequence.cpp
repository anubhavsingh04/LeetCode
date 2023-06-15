class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int prev=-1;prev<n-1;prev++) dp[prev+1][n]=0;
        for(int curr=n-1;curr>=0;curr--)
        {
            for(int prev=curr-1;prev>=-1;prev--)
            {
                int pick=0,notpick;
                if(prev==-1||nums[curr]>nums[prev]) {
                    pick=1+dp[curr+1][curr+1];
                }
                notpick= dp[prev+1][curr+1];

                 dp[prev+1][curr]=max(pick,notpick);
            }
        }
        return dp[0][0];
    }
};