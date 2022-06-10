// KADANES ALGO--> we will carry the subarray sum as long as it is greater than zero
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum=nums[0];
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            maxsum=max(maxsum,sum);
            if(sum<0) sum=0;
        }
        return maxsum;
    }
};

// Gives tle
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int max_sum = INT_MIN;
        
//         for(int i=0; i<nums.size(); i++){
//             int curr_sum = 0;
//             for(int j=i; j<nums.size(); j++){
//                 curr_sum += nums[j];
//                 //cout<<curr_sum<<endl;
//                 max_sum = max(max_sum, curr_sum);
//             }
//         }
//     return max_sum;
//     }
// };
