class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newinterval) {
        vector<vector<int>>ans;
        int n=intervals.size();
        int i=0;
        while(i<n && intervals[i][1]<newinterval[0]){
            ans.push_back(intervals[i]);
            i++;
        }
        // overlapping case
        while(i<n && (intervals[i][0]<=newinterval[1] || intervals[i][1]<=newinterval[1]))
        {
            newinterval[0]=min(newinterval[0],intervals[i][0]);
            newinterval[1]=max(newinterval[1],intervals[i][1]);
            i++;
        }
        ans.push_back(newinterval);
        while(i<n) {
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};