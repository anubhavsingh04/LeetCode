class Solution {
public:
    bool halvesAreAlike(string s) {
        int cnt=0,len=s.size();
        unordered_set<char>st={'a','A','e','E','i','I','o','O','u','U'};
        for(int i=0;i<len;i++){
            if(st.count(s[i]))
            {
                if(i<len/2) cnt++;
                else cnt--;
            }
        }
        return cnt==0;
    }
};