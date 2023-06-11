class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int total=accumulate(nums.begin(),nums.end(),0);
        if(total+target<0||(total+target)%2==1) return 0;
        target=(total+target)/2;
        
        vector<vector<int>>dp(n,vector<int>(target+1,0));
        
        for(int i=0;i<n;i++) dp[i][0]=1; // target==0 
        if(nums[0]!=0 && nums[0]<=target) dp[0][nums[0]]=1; 
        // agr array me ek hi element hai to jo nums[0] ki value hogi vahi achieve kr skte hain
        if(nums[0]==0 ) dp[0][0]=2; // two possibilities take or not take
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=target;j++)
            {
                int notpick=dp[i-1][j];
                int pick=0;
                if(nums[i]<=j){
                    pick=dp[i-1][j-nums[i]];
                }
                 dp[i][j]=pick+notpick;
            }
        }
        return dp[n-1][target];
    }
};