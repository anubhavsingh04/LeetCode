class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0,cnt=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            cnt=0;
            
            while(i<n && nums[i]==0){
                i++;
                cnt++;
            }
            if(cnt>0)
            i--;
            ans+=(cnt*(cnt+1)/2);
            cnt=0;
        }
        return ans;
    }
};