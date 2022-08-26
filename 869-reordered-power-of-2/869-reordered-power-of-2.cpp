// two maps will be equal if all the digits and freq are equal
// store the digits of n in m
// check for the digits in all powers of 2 
// class Solution {
// public:
//     bool isequal(int n,map<int,int>m)
//     {
//         map<int,int>m2;
//         while(n)
//         {
//             m2[n%10]++;
//             n/=10;
//         }
//         return m2==m; 
//     }
//     bool reorderedPowerOf2(int n) {
//         map<int,int>digits;
//         while(n)
//         {
//             digits[n%10]++;
//             n/=10;
//         }
//         for(int i=0;i<32;i++)
//         {
//             if(isequal((1<<i),digits))
//                 return true;
//         }
//         return false;
//     }
// };




class Solution {
public:
    string sort_(int n)
    {
        string s=to_string(n);
        sort(s.begin(),s.end());
        return s;
    }
    bool reorderedPowerOf2(int n) {
        string str=sort_(n);
        for(int i=0;i<32;i++)
        {
            if(sort_(1<<i)==str)
                return true;
        }
        return false;
    }
};
