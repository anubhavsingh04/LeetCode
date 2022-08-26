class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt=0,sum=0,n=nums.size(),ans=0;
        unordered_map<int,int>m;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(sum==k) ans++;
            if(m.find(sum-k)!=m.end())
            {
                ans+=m[sum-k];
            }
            m[sum]++;
        }
        return ans;
    }
};