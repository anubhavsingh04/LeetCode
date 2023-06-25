class Solution {
public:
    const int mod=1e9+7;
    int rec(int curr,int end,int fuel,vector<int>& nums,vector<vector<int>>&dp)
    {
        if(fuel<0) return 0;
        // if(nums[curr]==end) return 1;
        // int notpick=rec(curr,)
        if(dp[curr][fuel]!=-1) return dp[curr][fuel];
        int pick=0;
        if(curr==end) pick=1;
        else pick=0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(i!=curr && fuel>=abs(nums[curr]-nums[i])) 
                pick=(pick+rec(i,end,fuel-abs(nums[i]-nums[curr]),nums,dp))%mod;
        }
        return dp[curr][fuel]=pick;
    }
    int countRoutes(vector<int>&locations, int start, int finish, int fuel) {
        int n=locations.size();
        vector<vector<int>>dp(n+1,vector<int>(fuel+1,-1));
        return rec(start,finish,fuel,locations,dp);
    }
};