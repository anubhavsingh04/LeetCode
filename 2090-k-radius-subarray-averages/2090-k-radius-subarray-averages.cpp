class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        long long n=nums.size(),size=2*k+1,sum=0,left=0,right=0;
        vector<int>ans(n,-1);
        if(n<size) return ans;
        for(int i=0;i<size;i++) sum+=nums[i];
        right=2*k;
        for(int i=k;i<n-k;i++)
        {
            ans[i]=sum/size;
            cout<<sum<<endl;
            sum-=nums[left++];
            if(right+1<n)
            sum+=nums[++right];
        }
        return ans;
    }
};