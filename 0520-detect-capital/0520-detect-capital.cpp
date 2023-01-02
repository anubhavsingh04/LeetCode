class Solution {
public:
    bool detectCapitalUse(string s) {
        for(int i=1;i<s.size();i++){
            if( (islower(s[0]) && isupper(s[i])) || (isupper(s[1])!=isupper(s[i]))) 
            return false;
        }
        return true;
    }
};