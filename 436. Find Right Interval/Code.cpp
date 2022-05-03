class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        // support variables
        int len = intervals.size();
        vector<int> res(len);
        pair<int, int> pos[len];
        auto endOfPos = pos + len;
        // populating and sorting the map of positions
        for (int i = 0; i < len; i++) pos[i] = {intervals[i][0], i};
        sort(pos, endOfPos);
        // finding the matching right interval
        for (int i = 0; i < len; i++) {
            auto p = lower_bound(pos, endOfPos, intervals[i][1], [](auto it, int val){return it.first < val;});
            res[i] = p == endOfPos ? -1 : p->second;
        }
        return res;
    }
};