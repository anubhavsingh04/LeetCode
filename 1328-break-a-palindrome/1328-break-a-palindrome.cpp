class Solution {
public:
    bool ispalindrome(string &s)
    {
        int i=0,j=s.size()-1;
        while(i<j)
        {
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
    string breakPalindrome(string s) {
        int n=s.size();
        if(n==1) return "";
        int i=0;
        while(i<n)
        {
            if(s[i]!='a')
            {
                string tmp=s;
                tmp[i]='a';
                if(!ispalindrome(tmp))
                {
                    s[i]='a';
                    break;
                }
            }
            i++;
        }
        if(i==n)
        {
            s[n-1]='b';
        }
        return s;
    }
};