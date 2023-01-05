// Activity selection problem 
class Solution {
public:
    static bool cmp(pair<int,int>a,pair<int,int>b)
    {
        return a.second<b.second;
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        vector<pair<int,int>>v;
        int n=points.size();
        for(int i=0;i<points.size();i++)
        {
            v.push_back({points[i][0],points[i][1]});
        }
        sort(v.begin(),v.end(),cmp);
        int endtime=v[0].second;
        int ans=1;
        for(int i=0;i<n;i++)
        {
            if(v[i].first>endtime)
            {
                ans++;
                endtime=v[i].second;
            }
        }
        return ans;
    }
};