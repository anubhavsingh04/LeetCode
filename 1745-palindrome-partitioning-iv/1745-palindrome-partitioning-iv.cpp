class Solution {
public:
    vector<vector<int>>dp;
    bool ispalindrome(string &s,int i,int j)
    {
        while(i<j)
        {
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
    int rec(int i,int n,int k,string &s)
    {
        if(i>=n) return 0;
        if(dp[i][k]!=-1) return dp[i][k];
        if(k==1){
            if(ispalindrome(s,i,n-1)) return dp[i][k]=true;
            else return dp[i][k]=false;
        }
        int ans=0;
        for(int j=i;j<n;j++)
        {
            if(ispalindrome(s,i,j)) ans=ans|rec(j+1,n,k-1,s);
        }
        return dp[i][k]=ans;
    }
    bool checkPartitioning(string s) {
        int n=s.size();
        dp.resize(n+1,vector<int>(4,-1));
        return rec(0,n,3,s);
    }
};