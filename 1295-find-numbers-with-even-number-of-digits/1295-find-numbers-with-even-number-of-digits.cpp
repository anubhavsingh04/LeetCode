// even no ke lsb pe zero hota hai aur 1 ke lsb pe 1 hota h

// class Solution {
// public:
//     int findNumbers(vector<int>& nums) {
//         int ans=0;
//         for(auto &i:nums)
//         {
//             string s=to_string(i);
//             if((s.size()&1)==0) 
//                 ans++;
//         }
//         return ans;
//     }
// };


// if we take log of any no on base 10 it will give no of digit in that no -1
// means agr log ans odd de rha hai then no of digits even rha hoga us no me 
// class Solution {
// public:
//     int findNumbers(vector<int>& nums) {
//         int ans=0;
//         for(auto &i:nums)
//         {
//             if((int)log10(i)&1)
//                 ans++;
//         }
//         return ans;
//     }
// };




// we can also use if else to check
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans=0;
        for(auto &i:nums)
        {
            if(i>9 && i<1e2)
                ans++;
            else if(i>999 && i<1e4)
                ans++;
            else if(i>99999 && i<1e6)
                ans++;   
        }
        return ans;
    }
};