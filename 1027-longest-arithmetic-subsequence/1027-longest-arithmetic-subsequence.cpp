class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        if(n<=2) return n;
        int ans=2;
        vector<vector<int>>dp(n+1,vector<int>(1005,1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                int diff=nums[i]-nums[j]+500;
                if( 1+dp[j][diff]>dp[i][diff]) dp[i][diff]=1+dp[j][diff];
                    
                ans=max(ans,dp[i][diff]);
            }
        }
        return ans;
    }
};