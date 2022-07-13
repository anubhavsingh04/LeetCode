class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        vector<int> res;
        auto sub_sum = 0, half_sum = accumulate(begin(nums), end(nums), 0) / 2;
        priority_queue<int> pq(begin(nums), end(nums));
        while (sub_sum <= half_sum) {
            res.push_back(pq.top());
            sub_sum += res.back();
            pq.pop();
        }
        return res;
    }
};



// class Solution {
// public:
//     vector<int> minSubsequence(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         int n=nums.size();
//         vector<int>ans;
//         int sum=0;
//         int s2=accumulate(nums.begin(),nums.end(),0)/2;
//         for(int i=n-1;i>=0;i--)
//         {
//             if(sum>s2) break;
//             sum+=nums[i];
//             ans.push_back(nums[i]);
//         }
//         return ans;
//     }
// };