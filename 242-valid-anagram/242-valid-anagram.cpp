// TC: O(nlogn) space: O(1)

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size()!=t.size()) return false;
        
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        return s==t;            
    }
};


// Using map TC: O(n) space: O(n)
// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         if(s.size()!=t.size()) return false;
//         map<char,int>m;
//         for(int i=0;i<s.size();i++)
//         {
//             m[s[i]]++;
//             m[t[i]]--;
//         }
//         for(auto &x:m)
//         {
//             if(x.second!=0) return false;
//         }
//         return true;
//     }
// };



// TC: O(n) space O(n)

// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         if(s.size()!=t.size()) return false;
//         map<char,int>m1,m2;
//         for(int i=0;i<s.size();i++)
//         {
//             m1[s[i]]++;
//             m2[t[i]]++;
//         }
//         return m1==m2;
//     }
// };


// Using multiset 
// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         if(s.size()!=t.size()) return false;
//         multiset<char>s_set,t_set;
//         for(int i=0;i<s.size();i++)
//         {
//             s_set.insert(s[i]);
//             t_set.insert(t[i]);
//         }
//         return s_set==t_set;
//     }
// };
