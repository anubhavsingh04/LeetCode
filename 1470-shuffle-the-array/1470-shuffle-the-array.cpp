class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int maxi=1001;
        for(int i=n;i<2*n;i++)
        {
            nums[i]=nums[i]*maxi+nums[i-n];
        }
        int idx=0;
        for(int i=n;i<2*n;i++)
        {
            nums[idx]=nums[i]%maxi;
            nums[idx+1]=nums[i]/maxi;
            idx+=2;
        }
        return nums;
    }
};