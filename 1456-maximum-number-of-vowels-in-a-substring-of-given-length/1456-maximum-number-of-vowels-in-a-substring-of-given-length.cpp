class Solution {
public:
    static bool isvowel(char ch)
    {
        string s="aeiou";
        set<char>st(s.begin(),s.end());
        return st.count(ch);
    }
    int maxVowels(string s, int k) {
        int n=s.size();
        int ans=0;
        // if(k<s.size()) return 0;
        int i=0,j=0;
        int count=0;
        while(j!=k)
        {
            if(isvowel(s[j])) count++;
            j++;
        }
        ans=max(ans,count);
        while(j<n)
        {
            if(!isvowel(s[i]) && isvowel(s[j])) count++;
            if(isvowel(s[i]) && !isvowel(s[j])) count--;
            ans=max(ans,count);
            i++;
            j++;
        }
        return ans;
    }
};