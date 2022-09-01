class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.size(),m=t.size();
        int i=0,j=0;
        while(j<m)
        {
            if(s[i]==t[j]) i++,j++;
            else j++;
        }
        return i==n;
    }
};