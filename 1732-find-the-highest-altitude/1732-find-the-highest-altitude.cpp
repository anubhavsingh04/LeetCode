// gain in height =curr_height-prev_height 
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans=0,prev=0;
        for(int i=0;i<gain.size();i++)
        {
            ans=max(ans,prev+gain[i]);
            prev+=gain[i];
        }
        return ans;
    }
};