class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans=nums[0]+nums[1]+nums[2];
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            int x=i+1,y=n-1;
            while(x<y)
            {
                int sum=nums[i]+nums[x]+nums[y];
                if(abs(sum-target)<abs(ans-target))
                    ans=sum;
                else if(sum<target) x++;
                else y--;
            }
        }
        return ans;
    }
};