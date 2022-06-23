class Solution {
public:
    
    int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return __gcd(nums[0],nums[nums.size()-1]);
    }
};



// class Solution {
// public:
//     int gcd(int a,int b)
//     {
//         if(b==0)
//             return a;
//         return gcd(b,a%b);
//     }
//     int findGCD(vector<int>& nums) {
//         int smallest=*min_element(nums.begin(),nums.end());
//         int largest=*max_element(nums.begin(),nums.end());
//         return gcd(smallest,largest);
//     }
// };



// class Solution {
// public:
//     int findGCD(vector<int>& nums) {
//         int smallest=*min_element(nums.begin(),nums.end());
//         int largest=*max_element(nums.begin(),nums.end());
//         return __gcd(smallest,largest);
//     }
// };

