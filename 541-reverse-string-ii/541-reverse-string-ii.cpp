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
            if(i+k<n)
            {
                 reverse(s.begin()+i,s.begin()+i+k);
            }
            else 
            {
                reverse(s.begin()+i,s.end());
            }
            // reverse(s.begin()+i,s.begin()+i+k);
            i+=2*k;
            
        }
        return s;
    }
};