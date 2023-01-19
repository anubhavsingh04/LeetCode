class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum=0,ans=0;
        unordered_map<int,int>mp;
        mp[0]=1; // our currsum is 0 which has occoured once 
        // if s1%k=x and s2%k=x then subarray starting from s1 to s2 is divisible by k
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            int rem=sum%k;
            if(rem<0) rem+=k;
            if(mp.find(rem)!=mp.end())
            {
                ans+=mp[rem];
            }
            mp[rem]++;
        }
        return ans;
    }
}; 