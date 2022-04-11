class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<1000;i++)
        {
            // calcute the index of that value which is greater than or equal to i
            int p=nums.end()-lower_bound(nums.begin(),nums.end(),i); 
            if(p==i)
            return p; 
        }
        return -1;
    }
};

// Brute foce 
// class Solution {
// public:
//     int specialArray(vector<int>& nums) {
//         for(int i=1;i<1000;i++){
//             int cnt=0;
//             for(int j=0;j<nums.size();j++){
//                 if(nums[j]>=i) cnt++;
//             }
//             if(cnt==i)
//                 return i;
//         }
//         return -1;
//     }
// };