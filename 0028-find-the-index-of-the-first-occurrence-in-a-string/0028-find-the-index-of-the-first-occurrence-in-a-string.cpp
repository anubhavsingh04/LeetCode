// class Solution {
// public:
//     int strStr(string haystack, string needle) {
//         if(needle.size()==0)
//          return 0;
//         if(haystack.size()<needle.size())
//           return -1;  
//         int n=needle.size();
//         string str;
//         for(int i=0;i<=haystack.size()-n;i++)
//         {
//             str=haystack.substr(i,n);
//             if(str==needle)
//              return i;   
//         }
//         return -1;
//     }
// };

// // TWO POINTER 

// class Solution{
// public:
// int strStr(string haystack, string needle) 
//     {
//         if(needle=="")
//             return 0;
        
//         int i=0,j=0;
//         while(i<haystack.size() && j<needle.size())
//         {
//             if(haystack[i]==needle[j])
//             {
//                 i++;
//                 j++;
//                 if(j==needle.size()) return i-needle.size();
//             }
//             else
//             { 
//                 i=(i+1-j);
//                 j=0;
//             }            
//         }        
//         return -1;
//     }
// };

// using c++ stl 

class Solution{
public:
int strStr(string haystack, string needle) 
    {
        return haystack.find(needle);
    }
};