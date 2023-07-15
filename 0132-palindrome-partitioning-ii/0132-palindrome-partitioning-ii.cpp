class Solution {
public:
    bool ispalindrome(string &s,int i,int j)
    {
        while(i<j)
        {
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
    int rec(int i,int j,string &s,vector<int>&dp)
    {
        if(i>=j || ispalindrome(s,i,j)) return 0;
        if(dp[i]!=-1) return dp[i];
        int mini=INT_MAX;
        for(int k=i;k<j;k++)
        {
            if(ispalindrome(s,i,k)){
                int cost=1+rec(k+1,j,s,dp);
                mini=min(mini,cost);
            }
        }
        return dp[i]=mini;
    }
    int minCut(string s) {
        int n=s.size();
        vector<int>dp(n+1,-1);
        return rec(0,n-1,s,dp);
    }
};