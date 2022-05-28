class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        map<string,int>m;
        for(int i=0;i<senders.size();i++)
        {
            int cnt=1;
            for(int j=0;j<messages[i].size();j++)
            {
                if(messages[i][j]==' ') cnt++;
            }
            // m.insert({senders[i],m[senders[i]]+cnt});
            m[senders[i]]+=cnt;
        }
        int maxi=INT_MIN;
        string ans;
        for(auto &i:m)
        {
            if(i.second>maxi)
            {
                ans=i.first;
            }
            else if(i.second==maxi)
            { 
                if(i.first>ans) ans=i.first;
            }
            maxi=max(maxi,i.second);
        }
        return ans;
    }
};