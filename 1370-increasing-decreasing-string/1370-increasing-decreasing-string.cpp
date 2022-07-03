class Solution {
public:
    string sortString(string s) {
        vector<int>v(26,0);
        string ans="";
        int cnt=0;
        for(auto &i:s)
        {
            v[i-'a']++;
            cnt++;
        }
        while(cnt)
        {
            for(int i=0;i<26;i++)
            {
                if(v[i]>0)
                {
                    ans+=i+'a';
                    cnt--;
                    v[i]--;
                }
            }
            for(int i=25;i>=0;i--)
            {
                if(v[i]>0)
                {
                    ans+=i+'a';
                    cnt--;
                    v[i]--;
                }
            }
        }
        return ans;
    }
};