class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        map<int,int>m;
        int sum=0,ans=0;
        int i=0,j=0,n=nums.size();
        while(j<n)
        {
            sum+=nums[j];
            while(m.find(nums[j])!=m.end())
            {
                sum-=nums[i];
                m.erase(nums[i]);
                i++;
            }
            m[nums[j]]++;
            ans=max(ans,sum);
            j++;
        }
        return ans;
    }
};