// KADANES ALGO--> we will carry the subarray sum as long as it is greater than zero
// traverse in array
// Take two variable sum and maxsum=nums[0] sum is to store the sum of subarray till i index and 
// in each step we take max(sum,maxsum) i.e. if sum >=0 then it will be included in the subarray 
// else if sum<0 assign sum=0 


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int ans=INT_MIN;
        int sum=0,n=nums.size();
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            ans=max(ans,sum);
            sum=max(sum,0);
        }
        return ans;
        
        // for min subarray sum
        // long long ans=INT_MAX;
        // int sum=0;
        // for(int i=0;i<n;i++)
        // {
        //     sum+=nums[i];
        //     ans=min(ans,sum);
        //     sum=min(sum,0);
        // }
        // return ans;
    }
};


// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int maxsum=nums[0];
//         int sum=0;
//         for(int i=0;i<nums.size();i++){
//             sum+=nums[i];
//             maxsum=max(maxsum,sum);
//             if(sum<0) sum=0;
//         }
//         return maxsum;
//     }
// };


// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//        int sum=0,max_sum=nums[0];
//         int n=nums.size();
//         for(int i=0;i<n;i++)
//         {
//             sum+=nums[i];
//             max_sum=max(max_sum,sum);
//             if(sum<0) sum=0;
//         }
//         return max_sum;
//     }
// };




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


