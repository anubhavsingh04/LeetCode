class Solution {
public:
    int rec(int i,vector<int>&stones,vector<int>&dp)
    {
        if(i>=stones.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        
        int take1=stones[i]-rec(i+1,stones,dp);
        int take2=INT_MIN;
        if(i+1<stones.size()) take2= stones[i]+stones[i+1]-rec(i+2,stones,dp);
        int take3=INT_MIN;
        if(i+2<stones.size()) take3=stones[i]+stones[i+1]+stones[i+2]-rec(i+3,stones,dp);
        return dp[i]=max({take1,take2,take3});
    }
    string stoneGameIII(vector<int>& stoneValue) {
        vector<int>dp(stoneValue.size()+1,-1);
        int diff=rec(0,stoneValue,dp);
        if(diff>0) return "Alice";
        else if(diff<0) return "Bob";
        else return "Tie";
    }
};