class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans=0,len=0;
        unordered_map<int,int>mp;
        
        for(auto &i:nums) mp[i]++;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(nums[i]-1)!=mp.end()) continue;
            int count=1;
            int j=1;
            while(mp.count(nums[i]+j)){
                j++;
                count++;
            }
            ans=max(ans,count);
        }
        return ans;
    }
};