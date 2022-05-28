class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            cnt+= m[nums[i]+k]+m[nums[i]-k];
            m[nums[i]]++;
        }
        return cnt;
    }
};