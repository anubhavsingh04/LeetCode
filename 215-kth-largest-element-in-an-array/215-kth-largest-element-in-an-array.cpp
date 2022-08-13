// Kth largest element is (n-k+1)th smallest 

// TC: O(nlogn) space O(1)
// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         sort(nums.begin(),nums.end());
//         int n=nums.size();
//         return nums[n-k];
//     }
// };

// Using min heap TC:O(nlogk)

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto &i:nums)
        {
            pq.push(i);
            if(pq.size()>k)
                pq.pop();
        }
        return pq.top();
    }
};