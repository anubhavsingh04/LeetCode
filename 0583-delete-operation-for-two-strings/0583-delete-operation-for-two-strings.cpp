class Solution {
public:
    int minDistance(string str1, string str2) {
        // min no of deletion: len(str1)-len(lcs)
	    // min no of insertion: len(str2)-len(lcs) // here we have to delete only 
        // those character which are not in LCS but in str1--> they need to be removed (len(str1)-len(lcs))
        // those character which are not in LCS but in str2--> they need to be removed len(str2)-len(lcs)
	    int m=str1.size();
	    int n=str2.size();
	    vector<vector<int>>dp(m+1,vector<int>(n+1,0));
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
	    int lcslength=dp[m][n];
	    return str1.size()-lcslength+str2.size()-lcslength;
    }
};