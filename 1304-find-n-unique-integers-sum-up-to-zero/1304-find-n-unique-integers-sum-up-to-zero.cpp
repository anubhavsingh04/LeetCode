// floor(x/2) val gives less or equal to x
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>ans;
        if(n&1) ans.push_back(0);
        for(int i=1;i<=floor(n/2);i++)
        {
            ans.push_back(i);
            ans.push_back(-i);
        }
        return ans;
    }
};



// if n is odd then push 0 now n becomes even start pushing n ,-n 
// class Solution {
// public:
//     vector<int> sumZero(int n) {
//         vector<int>ans;
//         if(n&1)
//         {
//             ans.push_back(0);
//             n--;
//         }
        
//         while(n)
//         {
//             ans.push_back(n);
//             ans.push_back(-1*n);
//             n-=2;
//         }
//         return ans;
//     }
// };