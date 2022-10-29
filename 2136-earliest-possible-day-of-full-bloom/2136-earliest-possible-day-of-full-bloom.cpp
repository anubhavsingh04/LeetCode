class Solution {
public:
    
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>>v; // growtime,planttime (Jo grow hone me jada din laga rhe hai unko pehle plant kro)
        int n=growTime.size();
        for(int i=0;i<n;i++)
        {
            v.push_back({growTime[i],plantTime[i]});
        }
        sort(v.rbegin(),v.rend());
        int curr_day=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            curr_day+=v[i].second;
            ans=max(ans,curr_day+v[i].first);
        }
        return ans;
    }
};