class Solution {
public:
    int longestSubsequence(vector<int>& nums, int d) {
        int n=nums.size();
        int ans=1;
       unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            if(mp.count(nums[i]-d)){
                mp[nums[i]]=1+mp[nums[i]-d];
            }
            else
            mp[nums[i]]=1;
                ans=max(ans,mp[nums[i]]);
        }
        return ans;
    }
};