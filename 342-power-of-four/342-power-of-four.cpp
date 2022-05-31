// (num & 0xAAAAAAAA) == 0? 0xAAAAAAAA is 10101010‭10101010101010101010101010101010‬ in binary. ANDing a 32-bit number with 0xAAAAAAAA means setting all even bits to 0. After clearing even bits, if the number is larger than 0, it means the 1 bit is in an odd position and num is just a power of 2. Otherwise num is a power of 4 (or a zero).

class Solution {
public:
    bool isPowerOfFour(int n) {
        if((n>0)&&(n&n-1)==0&&(n & 0xAAAAAAAA) == 0) return true;
        return false ;
    }
};


// class Solution {
// public:
//     bool isPowerOfFour(int n) {
//         if((n>0)&&(n&n-1)==0&&(n-1)%3==0) return true;
//         return false ;
//     }
// };