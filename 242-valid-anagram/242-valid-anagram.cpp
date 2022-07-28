// TC: O(n) space: O(1)

// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         if (s.size()!=t.size()) return false;
        
//         sort(s.begin(), s.end());
//         sort(t.begin(), t.end());
        
//         return s==t;            
//     }
// };


// Using map 
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        map<char,int>m;
        for(int i=0;i<s.size();i++)
        {
            m[s[i]]++;
            m[t[i]]--;
        }
        for(auto &x:m)
        {
            if(x.second!=0) return false;
        }
        return true;
    }
};