class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long int n=nums.size();
        map<long long,long long>m;
        long long cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            cnt+=m[i-nums[i]];
            m[i-nums[i]]++;
        }
        long long total=n*(n-1)/2;
        return total-cnt;
    }
};