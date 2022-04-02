class Solution {
// Palindrome check function
    bool isPal(string s, int l, int r)
    {
        while(l < r)
        {
            if(s[l] != s[r])
                return false;
            
            l++;
            r--;
        }
        
        return true;
    }
public:
    bool validPalindrome(string s) {
        int st = 0, en = s.length()-1;
        
        while(st < en)
        {
            if(s[st] != s[en])
            {
                return isPal(s, st+1, en) || isPal(s, st, en-1);
            }
            st++;
            en--;
        }
        return true;
    }
};