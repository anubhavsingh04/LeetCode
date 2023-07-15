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
    
    int minCut(string s) {
        int n=s.size();
        vector<int>dp(n+1,0);
        dp[n-1]=0;
        for(int i=n-1;i>=0;i--)
        {
            int mini=INT_MAX;
            for(int k=i;k<n;k++)
            {
                if(ispalindrome(s,i,k)){
                    int cost=1+dp[k+1];
                    mini=min(mini,cost);
                }
            }
             dp[i]=mini;
        }
        return dp[0]-1;
    }
};