// Memoizzation
class Solution {
public:
   int rec(vector<int>&cuts,int i,int j,vector<vector<int>>&dp)
    {
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MAX;
        for(int idx=i;idx<=j;idx++)
        {
            int cost=cuts[j+1]-cuts[i-1]+rec(cuts,i,idx-1,dp)+rec(cuts,idx+1,j,dp);
            ans=min(ans,cost);
        }
        return dp[i][j]=ans;
    }
    int minCost(int n, vector<int>& cuts) {
        int c=cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        
        vector<vector<int>>dp(c+1,vector<int>(c+1,-1));
        return rec(cuts,1,c,dp);
    }
};