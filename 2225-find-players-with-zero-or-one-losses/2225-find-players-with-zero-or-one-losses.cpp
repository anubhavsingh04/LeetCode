class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,pair<int,int>>mp;
        for(auto i:matches)
        {
            int a=i[0];
            int b=i[1];
            int win=1,lose=0;
            if(mp.count(a)){
                auto p=mp[a];
                win+=p.first;
                lose+=p.second;
            }
            mp[a]={win,lose};
            win=0,lose=1;
            if(mp.count(b)){
                auto p=mp[b];
                win+=p.first;
                lose+=p.second;
            }
            mp[b]={win,lose};
        }
        vector<int>ans1,ans2;
        for(auto i:mp)
        {
            int a=i.first;
            auto b=i.second;
            if(b.second==0){
                ans1.push_back(a);
            }
            if(b.second==1){
                ans2.push_back(a);
            }
        }
        sort(ans1.begin(),ans1.end());
        sort(ans2.begin(),ans2.end());
        vector<vector<int>>ans;
        ans.push_back(ans1);
        ans.push_back(ans2);
        return ans;
    }
};