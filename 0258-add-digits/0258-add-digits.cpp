// class Solution {
// public:
//     int rec(int num)
//     {
//         if(num<10) return num;
//         int sum=0;
//         while(num)
//         {
//             sum+=num%10;
//             num/=10;
//         }
//         return rec(sum);
//     }
//     int addDigits(int num) {
//         return rec(num);
//     }
// };

// Check if the number is 0 or not . If num==0 , return 0. Else do the following.
// Check if (num%9)==0 . If it is true , return 9. Else return (num%9).


class Solution {
public:
    int addDigits(int num) {
        return (num%9==0)?(num!=0?9:0):num%9;
    }
};