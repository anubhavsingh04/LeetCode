class Solution {
public:
    string orderlyQueue(string s, int k) {
        string ans=s;
        if(k>1)
        {
            sort(s.begin(),s.end());
            return s;
        }
        if(k==1)
        {
            for(int i=0;i<s.size();i++)
            {
                s=s.substr(1)+s[0];
                ans=min(ans,s);
            }
        }
        return ans;
    }
};