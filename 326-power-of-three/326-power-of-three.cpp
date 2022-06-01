class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<1) return false;
        while(n!=1) 
        {
            if(n%3!=0) return false;
            n/=3;
        }
        return true;
    }
};

// Loop faster 62% tc: O(log3(n)) space O(1)
// class Solution {
// public:
//     bool isPowerOfThree(int n) {
//         if(!n) return false;
//         while(n%3==0)
//             n/=3;
//         return n==1;
//     }
// };

// recursive TC: o(Log3(n)) space o(log3(n)) fatser 35% 
// class Solution {
// public:
//     bool isPowerOfThree(int n) {
//         if(n<=1) return n==1;
//         return (n%3==0&&isPowerOfThree(n/3));
//     }
// };