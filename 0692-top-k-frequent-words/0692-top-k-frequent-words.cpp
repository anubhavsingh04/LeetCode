class Solution {
public:
    static bool cmp(pair<int,string>a,pair<int,string>b)
    {
        if(a.first!=b.first)
            return a.first>b.first;
        return a.second<b.second;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
       
        map<string,int>m;
        
        vector<pair<int,string>>v;
        for(auto &i:words)
        {
            m[i]++;
        }
        for(auto &i:m)
        {
            v.push_back({i.second,i.first});
        }
        sort(v.begin(),v.end(),cmp);
        vector<string>ans;
        for(auto &i:v)
        {
            ans.push_back(i.second);
            k--;
            if(k==0) break;
        }
        return ans;
    }
};