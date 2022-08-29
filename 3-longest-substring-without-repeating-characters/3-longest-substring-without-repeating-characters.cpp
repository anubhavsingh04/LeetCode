// TC: o(n) SC: O(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size(),i=0,j=0,ans=0;
        unordered_map<char,int>m;
       
        while(j<n){
            if(m.find(s[j])!=m.end()&&m[s[j]]>=i)
                i=m[s[j]]+1;
            
            m[s[j]]=j;
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         vector<int> v(256, -1);
//         int start = -1, maxRes = 0;
//         for(int i = 0; i < s.length(); i++) {
//             start = max(start, v[s[i]]);
//             v[s[i]] = i;
//             maxRes = max(maxRes, i - start);
//         }
//         return maxRes;
//     }
// };

// sliding window o(2*n)

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int n=s.size();
//         set<char>st;
//         int i=0,j=0;
//         int len=0;
//         while(j<n)
//         {
//             if(st.count(s[j])==0){
//                 st.insert(s[j]);
//                 len=max(len,j-i+1);
//                 j++;
//             }
//             else {
//                 st.erase(s[i]);
//                 i++;
//             }
//         }
//         return len;
//     }
// };