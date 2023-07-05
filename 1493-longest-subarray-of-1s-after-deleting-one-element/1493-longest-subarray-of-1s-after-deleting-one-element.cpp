// prevone will give pehle kitne continuous one aa chuke hain 0 ke bad 
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int one=0,prevone=0,ans=0,n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1) one++;
            else{
                ans=max(ans,prevone+one);
                prevone=one;
                one=0;
            }
        }
        ans=max(ans,prevone+one);
        if(ans==n) ans-=1;
        return ans;
    }
};