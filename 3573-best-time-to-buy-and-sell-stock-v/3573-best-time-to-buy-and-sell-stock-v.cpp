class Solution {
public:
    long long dp[1001][3][501];
    long long rec(int i,int val,int k,vector<int>&prices){
        if(i>=prices.size()){
            return val==0 ? 0 : -1e9;
        }
        if(dp[i][val][k]!=-1) return dp[i][val][k];
        long long notpick=rec(i+1,val,k,prices);
        long long pick=-1e9;
        if(k>0){
            if(val==0){
                pick=max(pick,-prices[i]+rec(i+1,1,k,prices));
                pick=max(pick,prices[i]+rec(i+1,2,k,prices));
            }
            else if(val==1){ // we have bough earlier 
                pick=max(pick,prices[i]+rec(i+1,0,k-1,prices));
            }
            else { // sold earlier - short selling
                pick=max(pick,-prices[i]+rec(i+1,0,k-1,prices));
            }
        }
        return dp[i][val][k]=max(pick,notpick);
    }
    long long maximumProfit(vector<int>& prices, int k) {
        int i=0,val=0;
        memset(dp,-1,sizeof(dp));
        return rec(i,val,k,prices);
    }
};