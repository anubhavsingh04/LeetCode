// class Solution {
// public:
//     bool isPalindrome(int x) {
//         if(x<0)
//             return false;
//         long long tmp=x;
//         long long revno=0;
//         while(tmp>0)
//         {
//             int rem=tmp%10;
//             revno=revno*10+rem;
//             tmp/=10;
//         }
//         return revno==x;
//     }
// };

class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x); 
        string s2 = s;
        reverse(s2.begin(), s2.end()); 
        return (s == s2); 
    }
};