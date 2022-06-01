// class Solution {
// public:
//     // if n%3==0 || n%3==1 then only n can be expressed as power of 2 
//     bool checkPowersOfThree(int n) {
//         int cnt=0;
//         vector<int>power(15);
//         while(n)
//         {
//             if(!(n%3)) 
//             {
//                 n/=3;
//                 cnt++;
//             }
//             else if(n%3==1)
//             {
//                 n--;
//                 power[cnt]++;
//                 if(power[cnt]>=2) return false;
//             }
//             else return false;
//         }
//         return true;
//     }
// };

class Solution {
public:
    // if n%3==0 || n%3==1 then only n can be expressed as power of 2 
    bool checkPowersOfThree(int n) {
        while(n)
        {
            if(n%3==2) return false;
            n/=3;
        }
        return true;
    }
};