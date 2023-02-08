class Solution {
public:
    int jump(vector<int>& nums) {
        int farthest=0,curr=0,n=nums.size(),ans=0;
        for(int i=0;i<n-1;i++) {
            farthest=max(farthest,nums[i]+i);
            if(i==curr) {
                curr=farthest;
                ans++;
            }
        }
        return ans;
    }
};