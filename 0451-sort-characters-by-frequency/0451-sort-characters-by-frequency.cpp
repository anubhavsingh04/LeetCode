// class Solution {
// public:
//     static bool cmp(pair<int,char>a,pair<int,char>b)
//     {
//         return a.first>b.first;
//     }
//     string frequencySort(string s) {
//         unordered_map<char,int>mp;
//         for(auto i:s)
//         {
//             mp[i]++;
//         }
//         vector<pair<int,char>>v;
//         for(auto i:mp)
//         {
//             v.push_back({i.second,i.first});
//         }
//         sort(v.begin(),v.end(),cmp);
//         string ans="";
//         for(auto i:v)
//         {
//             ans+=string(i.first,i.second);
//         }
//         return ans;
//     }
// };


class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(auto &i:s) mp[i]++;
        priority_queue<pair<int,int>>pq;
        for(auto &i:mp)
        {
            pq.push({i.second,i.first});
        }
        string ans="";
        while(!pq.empty())
        {
            int cnt=pq.top().first;
            char ch=pq.top().second;
            pq.pop();
            ans+=string(cnt,ch);
        }
        return ans;
    }
};