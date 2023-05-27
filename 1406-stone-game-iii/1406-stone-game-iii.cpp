class Solution {
public:
    int rec(int i,vector<int>&stones,vector<int>&dp)
    {
        if(i>=stones.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans=INT_MIN;
        ans=max(ans,stones[i]-rec(i+1,stones,dp));
        if(i+1<stones.size()) ans=max(ans,stones[i]+stones[i+1]-rec(i+2,stones,dp));
        if(i+2<stones.size()) ans=max(ans,stones[i]+stones[i+1]+stones[i+2]-rec(i+3,stones,dp));
        return dp[i]=ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        vector<int>dp(stoneValue.size()+1,-1);
        int diff=rec(0,stoneValue,dp);
        if(diff>0) return "Alice";
        else if(diff<0) return "Bob";
        else return "Tie";
    }
};