class Solution {
public:
    long long putMarbles(vector<int>& w, int k) {
        int n=w.size();
        if(k==0||k==n) return 0;
        vector<int>nums;
        for(int i=0;i<n-1;i++){
            nums.push_back(w[i]+w[i+1]);
        }
        sort(nums.begin(),nums.end());
        long long mini=0,maxi=0;
        for(int i=0;i<k-1;i++){
            mini+=nums[i];
            maxi+=nums[n-2-i];
        }
        return maxi-mini;
    }
};