class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int maxm_reachable_dist=startFuel;
        priority_queue<int>pq;
        int idx=0;
        int ans=0;
        while(maxm_reachable_dist<target)
        {
            while(idx<stations.size() && stations[idx][0]<=maxm_reachable_dist)
            {
                pq.push(stations[idx][1]);
                    idx++;
            }
            if(pq.empty()) return -1;
            maxm_reachable_dist+=pq.top();
            pq.pop();
            ans++;
        }
        return ans;
    }
};