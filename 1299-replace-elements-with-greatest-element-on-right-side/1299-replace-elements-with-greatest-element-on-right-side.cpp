class Solution {
public:
    vector<int> replaceElements(vector<int>& nums) {
        int n=nums.size();
        int maxi=nums[n-1];
        vector<int>ans(n);
        ans[n-1]=-1;
        for(int i=n-2;i>=0;i--)
        {
            maxi=max(maxi,nums[i+1]);
            ans[i]=maxi;
        }
        return ans;
    }
};