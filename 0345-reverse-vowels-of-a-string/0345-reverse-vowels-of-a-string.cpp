class Solution {
public:
    bool isvowel(char ch)
    {
        set<char>st;
        string s="aeiouAEIOU";
        for(auto i:s)
        {
            st.insert(i);
        }
        return st.find(ch)!=st.end();
    }
    string reverseVowels(string s) {
        int i=0,j=s.size()-1;
        while(i<j){
            bool flag1=false,flag2=false;
            if(isvowel(s[i])) flag1=true;
            if(isvowel(s[j])) flag2=true;
            if(flag1 && flag2) 
            {
                swap(s[i],s[j]);
                i++,j--;
            }
            if(!flag1) i++;
            if(!flag2) j--;
        }
        return s;
    }
};