// if the count of negative number is odd then we have to either exclude first or last one 
// we can do this in two pass 
// if zero occours then update currpdt to 1
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long ans=INT_MIN,left_pdt=1,right_pdt=1;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            left_pdt*=nums[i];
            right_pdt*=nums[n-i-1];
            ans=max(ans,max(left_pdt,right_pdt));
            if(left_pdt==0) left_pdt=1;
            if(right_pdt==0) right_pdt=1;
        }
        return ans;
    }
};



