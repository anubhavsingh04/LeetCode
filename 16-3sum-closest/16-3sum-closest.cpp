class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size(),sum=nums[1]+nums[2]+nums[3];
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            int j=i+1;
            int k=n-1;
            while(j<k)
            {
                int currsum=nums[i]+nums[j]+nums[k];
                if(abs(currsum-target)<abs(sum-target))
                    sum=currsum;
                else if(currsum<target)
                    j++;
                else 
                    k--;
            }
        }
        return sum;
    }
};