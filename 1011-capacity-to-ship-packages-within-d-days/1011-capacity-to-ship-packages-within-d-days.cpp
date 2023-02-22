class Solution {
public:
    bool is_possible(int mid,vector<int>&weights,int days) {
        int curr_weight=0;
        for(int i=0;i<weights.size();i++) {
            curr_weight+=weights[i];
            if(curr_weight>mid) {
                days--;
                curr_weight=weights[i];
                if(curr_weight>mid) return false;
            }
        }
        return days>0;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=0,high=1e9,ans=-1;
        while(low<=high) {
            int mid=(low+high)>>1;
            if(is_possible(mid,weights,days)) {
                ans=mid;
                high=mid-1;
            }else {
                low=mid+1;
            }
        }
        return ans;
    }
};