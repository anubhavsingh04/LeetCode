class Solution {
public:
    int compress(vector<char>& s) {
        int n=s.size();
        string ans="";
        ans+=s[0];
        int cnt=1;
        for(int i=1;i<n;i++)
        {
            if(s[i]==s[i-1])
            {
                cnt++;
            }
            else 
            {
                if(cnt>1)
                {
                    ans+=to_string(cnt);
                    cnt=1;
                }
                ans+=s[i];
            }
        }
        if(cnt>1)
        {
            ans+=to_string(cnt);
        }
        for(int i=0;i<ans.size();i++)
        {
            s[i]=ans[i];
        }
        return ans.size();
    }
};