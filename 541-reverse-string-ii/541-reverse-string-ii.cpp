// class Solution {
// public:
//     string reverseStr(string s, int k) {
//         int n=s.size();
//         string ans="";
//         int l=0;
//         while(l<n) {
//             string st="";
//             for(int i=0;i<k;i++) {
//                 if(l==n) {
//                     break;
//                 }
//                 st+=s[l];
//                 l+=1;
//             }
//             cout<<st<<"  "<<l<<endl;
//             reverse(st.begin(),st.end());
//             ans+=st;
//             for(int j=l;j<min(l+k,n);j++) {
//                 ans+=s[l];
//                 l++;
//             }
//             cout<<l<<endl;
//         }
//         return ans;
//     }
// };

class Solution {
public:
    string reverseStr(string s, int k) {
        int n=s.size();
        int i=0;
        while( i<s.size())
        {
            reverse(s.begin()+i,min(s.begin()+i+k,s.end()));
            i+=2*k;
            
        }
        return s;
    }
};