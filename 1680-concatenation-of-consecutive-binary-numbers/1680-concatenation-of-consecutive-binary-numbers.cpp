// class Solution {
// public:
//     const int mod=1e9+7;
//     string decitobinary(int n)
//     {
//         string s;
//         while(n)
//         {
//             if(n&1)
//             {
//                 s+='1';
//             }
//             else 
//             {
//                 s+='0';
//             }
//         }
//         return s;
//     }
    
//     int concatenatedBinary(int n) {
//         string ans="";
//         for(int i=1;i<=n;i++)
//         {
//             string x=decitobinary(i);
//             ans+=x;
//         }
//         return ans
//     }
// };

class Solution {
public:
    int concatenatedBinary(int n) {
        long res = 0, mod = 1e9+7, len_of_curr = 0;
        for (int i = 1; i <= n; i++) {
		
			// the len increases every time we reach a number which is a power of two.
            if ((i & (i-1)) == 0)
                len_of_curr++;
				
            res = (res << len_of_curr) % mod;
            res += i % mod;
        }
        return res;
    }
};