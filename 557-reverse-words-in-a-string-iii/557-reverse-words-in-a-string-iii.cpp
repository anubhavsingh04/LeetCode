class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        string ans;
        string res;
        for(int i=0;i<n;i++)
        {
            res="";
            while(i<s.size() && s[i]!=' ')
            {
                res+=s[i];
                i++;
            }
            reverse(res.begin(),res.end());
            ans+=res;
            ans+=' ';
        }
        ans.pop_back();
        return ans;
    }
};