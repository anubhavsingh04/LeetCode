// => (sum_j - sum_i) % k = 0
// => sum_j % k - sum % k = 0
// => sum_j % k = sum_i % k  
// eg 23,3,6,7 
// i=0 prefsum=23  23%6=5,m[5]=0;
// i=1 prefsum=5+2  7%6=1,m[1]=1;
// i=2 prefsum=1+4  5%6=5, m[5]=2;  this means at index 0 sum%k was 5 and at index 2 also sum%k is 5  
// means (prefixsum_till_index2-prefsum_till_index0)%k must be equal to 0
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n=nums.size();
        int prefsum=0;
        for(int i=0;i<n;i++)
        {
            prefsum+=nums[i];
            if(i>0 && prefsum%k==0) return true;
            prefsum=prefsum%k;
            // if we are again getting prefsum%k means from prev index to curr idx sum%k==0
            if(mp.find(prefsum)!=mp.end())  
            {
                if(i-mp[prefsum]>1) return true;
            }
            else 
            {
                mp[prefsum]=i;
            }
        }
        return false;
    }
};