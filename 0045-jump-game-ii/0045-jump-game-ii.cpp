class Solution {
public:
    int jump(vector<int>& nums) {
        int farthest=0,curr=0;
        int ans=0,n=nums.size();
        for(int i=0;i<n-1;i++)
        {
            farthest=max(farthest,i+nums[i]);
            if(i==curr)
            {
                curr=farthest;
                ans++;
            }
            if(nums[i]==0 && i==curr) return -1;
        }
        return ans;
    }
};