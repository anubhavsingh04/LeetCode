class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char>st={'a','e','i','o','u','A','E','I','O','U'};
        
        int i=0,j=s.size()-1;
        while(i<j){
            bool flag1=false,flag2=false;
            if(st.count(s[i])) flag1=true;
            if(st.count(s[j])) flag2=true;
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