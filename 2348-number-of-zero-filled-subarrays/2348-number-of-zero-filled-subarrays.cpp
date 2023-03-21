class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            nums[i]=abs(nums[i]);
        }
        long long ans=0,sum=0;
        long long n=nums.size();
        unordered_map<long long,long long>mp;
        mp[0]=1;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(mp.count(sum)){
                ans+=mp[sum];
            }
            mp[sum]++;
        }
        return ans;
    }
};