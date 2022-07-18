class Solution {
public:
    double myPow(double x, int n) {
        if(n<0)
        {
            x=1/x;
            n=abs(n);
        }
        double ans=1;
        while(n>0)
        {
            if(n&1)
            {
                ans*=x;
                n--;
            }
            else
            {
                x*=x;
                n/=2;
            }
        }
        return ans;
    }
};




// class Solution {
// public:
//     double myPow(double x, int n) {
        
//         if(n < 0) {
//             x = 1 / x;
//         } 
        
//         long num = abs(n);
        
//         double pow = 1;
        
//         while(num){ // equivalent to while(num != 0)
//             if(num & 1) { // equivalent to if((num & 1) != 0)
//                 pow *= x;
//                 num--;
//             }
//             x *= x;
//             num >>= 1;
//         }
        
//         return pow;
//     }
// };