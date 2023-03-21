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
                ans+=cnt;
            }
            if(cnt>0)
            i--;
        }
        return ans;
    }
};