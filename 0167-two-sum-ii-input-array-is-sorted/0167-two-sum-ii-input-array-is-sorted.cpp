class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int start=i+1,end=n-1;
            while(start<=end)
            {
                int mid=(start+end)>>1;
                if(nums[mid]==target-nums[i]) return {i+1,mid+1};
                else if(nums[mid]<target-nums[i]) start=mid+1;
                else end=mid-1;   
            }
        }
        return {};
    }
};

