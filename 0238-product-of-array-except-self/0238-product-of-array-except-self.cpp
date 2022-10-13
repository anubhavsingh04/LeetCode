class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zerocnt=count(nums.begin(),nums.end(),0);
        if(zerocnt>1) return vector<int>(nums.size(),0); 
        int n=nums.size();
        int pdt=1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=0) pdt*=nums[i];
        }
        for(int i=0;i<n;i++)
        {
            if(zerocnt) // all element should be 0 except one element which is zero
            {
                if(nums[i]==0) nums[i]=pdt; // if element is 0 then it will be replaced with pdt
                else nums[i]=0;
            }
            else
            {
                nums[i]=pdt/nums[i];
            }
        }
        return nums;
    }
};