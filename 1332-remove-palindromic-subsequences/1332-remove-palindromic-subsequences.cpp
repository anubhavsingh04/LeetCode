class Solution {
public:
    bool ispalindrome(string s,int start,int end)
    {
        if(start==end) return true;
        if(s[start]!=s[end]) return false;
        if(start<end) return ispalindrome(s,start+1,end-1);
        return true;
    }
    int removePalindromeSub(string s) {
        if(s=="") return 0;
        if(ispalindrome(s,0,s.size()-1)) return 1;
        else return 2;
    }
};