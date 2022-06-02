class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& nums) {
        int parts=0,sum=0;
        int total=accumulate(nums.begin(),nums.end(),0);
        if(total%3!=0) return false;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if((parts+1)*total/3==sum) parts++;
        }
        return parts>=3;
    }
};