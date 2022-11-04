class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        // length of shortst common supersequence will be len(str1)+len(str2)-len(lcs)
        int m=str1.size();
        int n=str2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0)); // for lcs 
        for(int i=1;i<m+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                if(str1[i-1]==str2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else 
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        // lcs length is in dp[m][n] 
        string s="";
        int i=m,j=n;
        while(i>0 && j>0)
        {
            if(str1[i-1]==str2[j-1])
            {
                s=str1[i-1]+s;
                i--,j--;
            }
            else 
            {
                if(dp[i][j-1]>dp[i-1][j])
                {
                    s=str2[j-1]+s;
                    j--;
                }
                else
                {
                    s=str1[i-1]+s;
                    i--;
                }
            }
        }
        while(i>0)
        {
            s=str1[i-1]+s;
            i--;
        }
        while(j>0)
        {
            s=str2[j-1]+s;
            j--;
        }
        // reverse(s.begin(),s.end());
        return s;
    }
};