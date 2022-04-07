// class Solution {
// public:
//     bool isPerfectSquare(int num) {
//         // 1=1  
//         // 4=1+3  
//         // 9=1+3+5
//         int i=1;
//         while (num>0)
//         {
//             num=num-i;
//             i+=2;
//             if(num==0)
//                 return true;
//         }
//         return false;
//     }
// };

class Solution{
public: 
    bool isPerfectSquare(int num) {
        int s=1,e=num;
        while(s<=e){
            long long int mid=s+(e-s)/2;
        if(mid*mid==num)
            return true;
        else if(mid*mid<num)
            s=mid+1;
        else 
            e=mid-1;   
        }
        return false ;
    }
};