// class Solution {
// public:
//     int maximum69Number (int num) {
//         string s=to_string(num);
//         for(auto &i:s)
//         {
//             if(i=='6')
//             {
//                 i='9';
//                 break;
//             }
//         }
//         return stoi(s);
//     }
// };

// 9669 + 300=9969
class Solution {
public:
    int maximum69Number (int num) {
        int tmp=num;
        int digit=0,right6posn=-1;
        while(tmp)
        {
            int rem=tmp%10;
            if(rem==6) right6posn=digit;
            digit++;
            tmp/=10;
        }
        if(right6posn==-1) return num;
        else return num+3*pow(10,right6posn);
    }
};
