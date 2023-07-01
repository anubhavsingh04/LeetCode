// we need to minimize the unfairness means try to divide equally
class Solution {
public:
    int rec(int idx,int k,vector<int>&v,vector<int>&nums)
    {
        if(idx==nums.size()) {
            int maxi=INT_MIN;
            for(int i=0;i<k;i++) maxi=max(maxi,v[i]);
            return maxi;
        }
        int ans=INT_MAX;
        for(int i=0;i<k;i++) {
            v[i]+=nums[idx];
            ans=min(ans,rec(idx+1,k,v,nums));
            v[i]-=nums[idx];
        }
        return ans;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int>v(k,0);
        return rec(0,k,v,cookies);
    }
};