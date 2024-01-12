class Solution {
public:
    bool halvesAreAlike(string s) {
        string str="aeiouAEIOU";
        set<char>st(str.begin(),str.end());
        int n=s.size();
        int a=0,b=0;
        for(int i=0;i<n;i++)
        {
            if(st.count(s[i])){
                if(i<n/2) a++;
                else b++;
            }
        }
        return a==b;
    }
};