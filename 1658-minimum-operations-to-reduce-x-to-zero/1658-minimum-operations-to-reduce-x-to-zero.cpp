class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int ans=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        sum-=x;
        if(sum==0) return nums.size();
        
        int i=0,j=0,s1=0;
        while(j<nums.size())
        {
            s1+=nums[j];
            while(i<nums.size()&&s1>sum)
            {
                s1-=nums[i];
                i++;
            }
            if(s1==sum){
                ans=max(ans,j-i+1);
            } 
            j++;
        }
        return ans==0?-1:nums.size()-ans;
    }
};