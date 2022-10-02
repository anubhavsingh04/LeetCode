class Solution {
public:
    #define mod 1000000007 
    int nways(int dice,int face,int target,vector<vector<int>>&dp)
    {
        if(target<0) return 0;
        if(dice==0 && target==0) return 1;
        if(dice==0 && target!=0) return 0;
        if(dice!=0 && target==0) return 0;
        
        // if(dice==0 && target==0) return 1;
        // if(dice<0 || target<0) return 0;
        
        if(dp[dice][target]!=-1) return dp[dice][target];
        
        int ans=0;
        for(int i=1;i<=face;i++)
        {
            ans=(ans%mod + nways(dice-1,face,target-i,dp)%mod)%mod;
        }
        return dp[dice][target]=ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return nways(n,k,target,dp);
    }
};