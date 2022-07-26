class Solution {
public:
    bool solve(string s,string t)
    {
        unordered_map<char,char>m;
        for(int i=0;i<s.size();i++)
        {
            if(m.find(s[i])!=m.end())
            {
                if(m[s[i]]!=t[i]) return false;
            }
            m[s[i]]=t[i];
        }
        return true;
    }
    bool isIsomorphic(string s, string t) {
        return solve(s,t)&&solve(t,s);
        // checking in both way to avoid s= badc and t = baba since no 
        // two character can map to same character 
    }
};




// class Solution {
// public:
//     bool isIsomorphic(string s, string t) {
//         vector<int>a(256,-1),b(256,-1); // 256 ascii character
//         for(int i=0;i<s.size();i++)
//         {
//             if(a[s[i]]!=b[t[i]]) return false;
//             a[s[i]]=i+1;
//             b[t[i]]=i+1;
//         }
//         return true;
//     }
// };