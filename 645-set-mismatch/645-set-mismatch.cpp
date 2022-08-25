class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        set<int>st;
        int n=nums.size();
        vector<int>ans(2);
        int sum=(n*(n+1))/2;
        for(auto &i:nums)
        {
            sum-=i;
            if(st.count(i)) ans[0]=i;
            st.insert(i);
        }
        ans[1]=sum+ans[0];
        return ans;
    }
};