class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        unordered_map<char,int>m;
        for(auto &i:t)
            m[i]++;
        int count=m.size();
        int ans=INT_MAX;
        int i=0,j=0,start=0;
        while(j<n)
        {
            if(m.find(s[j])!=m.end())
            {
                m[s[j]]--;
                if(m[s[j]]==0)
                    count--;
            }
            if(count==0)
            {
                while(count==0)
                {
                    if(ans>j-i+1)
                    {
                        ans=j-i+1;
                        start=i;
                    }
                    if(m.find(s[i])!=m.end())
                    {
                        m[s[i]]++;
                        if(m[s[i]]>0)
                            count++;
                    }
                    i++;
                }
            }
            j++;
        }
        return ans!=INT_MAX?s.substr(start,ans):"";
    }
};