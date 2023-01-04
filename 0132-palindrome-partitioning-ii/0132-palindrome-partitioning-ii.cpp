class Solution {
public:
    vector<vector<int>>dp;
    vector<vector<int>>dp2;
    bool ispalindrome(string &s,int i,int j)
    {
        if(i>=j) return true;
        if(dp2[i][j]!=-1) return dp2[i][j];
        if(s[i]==s[j]) return dp2[i][j]=ispalindrome(s,i+1,j-1);
        return dp2[i][j]=false;
    }
    int solve(string s,int i,int j)
    {
        if(i>=j) return dp[i][j]=0;
        if(ispalindrome(s,i,j)) return dp[i][j]=0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MAX;
        for(int k=i;k<j;k++)
        {
            if(!ispalindrome(s,i,k)) continue;
            int left=0,right=0;
            if(dp[i][k]!=-1) left= dp[i][k];
            else dp[i][k]=left=solve(s,i,k);
            if(dp[k+1][j]!=-1) right=dp[k+1][j];
            else dp[k+1][j]=right=solve(s,k+1,j);
            int tmpans=1+left+right;
            ans=min(ans,tmpans);
        } 
        return dp[i][j]=ans;
    }
    int minCut(string s) {
        int n=s.size();
        dp.resize(n+1,vector<int>(n+1,-1));
        dp2.resize(n+1,vector<int>(n+1,-1));
        return solve(s,0,n-1);
    }
};