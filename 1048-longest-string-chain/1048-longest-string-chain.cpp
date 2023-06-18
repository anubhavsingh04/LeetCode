class Solution {
public:
    bool isvalid(string &s1,string &s2)
    {
        if(s1.size()!=s2.size()+1) return false;
        int i=0,j=0;
        while(i<s1.size() ){
            if(j<s2.size() && s1[i]==s2[j]) {
                i++;
                j++;
            }
            else {
                i++; // i points to s1 which is larger 
            }
        }
        if(i==s1.size() && j==s2.size()) return true;
        return false;
        
    }
    static bool cmp(string& s1, string& s2){
        return s1.size() < s2.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        int n=words.size();
        vector<int>dp(n,1);
        int maxi=-1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(isvalid(words[i],words[j]) && 1+dp[j]>dp[i]) {
                    dp[i]=1+dp[j];
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};