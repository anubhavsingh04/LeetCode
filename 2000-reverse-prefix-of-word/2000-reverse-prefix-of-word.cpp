class Solution {
public:
    string reversePrefix(string s, char ch) {
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==ch)
            {
                reverse(s.begin(),s.begin()+i+1);
                break;
            }
        }
        return s;
    }
};