class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int ans=0;
        vector<bool>vis(nums.size());
        for(auto &i:nums)
        {
            int cnt=0;
            while(!vis[i])
            {
                vis[i]=true;
                cnt++;
                i=nums[i];
            }
            ans=max(ans,cnt);
        }
        return ans ;
    }
};