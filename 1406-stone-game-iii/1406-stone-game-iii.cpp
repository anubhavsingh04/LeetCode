class Solution {
public:
    string stoneGameIII(vector<int>& stones) {
        vector<int>dp(stones.size()+1,0);
        int n=stones.size();
        for(int i=n-1;i>=0;i--)
        {
            int take1=stones[i]-dp[i+1];
            int take2=INT_MIN;
            if(i+1<stones.size()) take2= stones[i]+stones[i+1]-dp[i+2];
            int take3=INT_MIN;
            if(i+2<stones.size()) take3=stones[i]+stones[i+1]+stones[i+2]-dp[i+3];
            dp[i]=max({take1,take2,take3});
        }
        int diff=dp[0];
        if(diff>0) return "Alice";
        else if(diff<0) return "Bob";
        else return "Tie";
    }
};