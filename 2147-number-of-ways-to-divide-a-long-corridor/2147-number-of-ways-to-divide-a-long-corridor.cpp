class Solution {
public:
    const int mod=1e9+7;
    int rec(int i,int cnt,string &s,int n,vector<vector<int>>&dp){
        if(i>n-1){
            return (cnt==2);
        }
        if(dp[i][cnt]!=-1) return dp[i][cnt];
        int ans=0;
        if(cnt==2){
            if(s[i]=='S'){
                ans=(ans+rec(i+1,1,s,n,dp))%mod;
            }
            else {
                ans=(ans+rec(i+1,0,s,n,dp))%mod;
                ans=(ans+rec(i+1,2,s,n,dp))%mod;
            }
        }
        else {
            if(s[i]=='S'){
                ans=(ans+rec(i+1,cnt+1,s,n,dp))%mod;
            }
            else {
                ans=(ans+rec(i+1,cnt,s,n,dp))%mod;
            }
        }
        return dp[i][cnt]= ans;
    }
    int numberOfWays(string s) {
        int cnt=0,i=0,n=s.size();
        vector<vector<int>>dp(n,vector<int>(3,-1));
        return rec(i,cnt,s,n,dp);
    }
};