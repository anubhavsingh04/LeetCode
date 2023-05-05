class Solution {
public:
    int maxVowels(string s, int k) {
        int n=s.size(),ans=0,i=0,j=0,count=0;
        string x="aeiou";
        set<char>st(x.begin(),x.end());
        while(j<n)
        {
            if(j<k)
            {
                if(st.count(s[j])) count++;
                j++;
            }
            else 
            {
                if(st.count(s[j])) count++;
                if(st.count(s[i])) count--;
                j++;
                i++;
            }
            ans=max(ans,count);
        }
        return ans;
    }
};