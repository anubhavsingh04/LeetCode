class Solution {
public:
    string sortVowels(string s) {
        string str="aeiouAEIOU";
        set<char>st(str.begin(),str.end());
        string word="";
        for(int i=0;i<s.size();i++)
        {
            if(st.count(s[i])) word+=s[i];
        }
        string t=s;
        sort(word.begin(),word.end());
        int j=0;
        for(int i=0;i<s.size();i++)
        {
            if(st.count(t[i]))
            {
                t[i]=word[j];
                j++;
            }
        }
        return t;
    }
};