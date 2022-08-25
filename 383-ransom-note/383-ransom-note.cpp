class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>m;
        for(auto &i:magazine)
        {
            m[i]++;
        }
        for(int i=0;i<ransomNote.size();i++)
        {
            if(m[ransomNote[i]]--<=0)
            return false;
        }
        return true;
    }
};




// class Solution {
// public:
//     bool canConstruct(string ransomNote, string magazine) {
//         unordered_map<char,int>m;
//         for(auto &i:magazine)
//         {
//             m[i]++;
//         }
//         for(int i=0;i<ransomNote.size();i++)
//         {
//             if(m[ransomNote[i]]>0)
//             m[ransomNote[i]]--;
//             else return false;
//         }
//         return true;
//     }
// };


// class Solution {
// public:
//     bool canConstruct(string ransomNote, string magazine) {
//         unordered_map<char,int>m;
//         for(auto &i:magazine)
//         {
//             m[i]++;
//         }
//         for(int i=0;i<ransomNote.size();i++)
//         {
//             if(m.find(ransomNote[i])!=m.end())
//             {
//                 if(m[ransomNote[i]]>0)
//                 m[ransomNote[i]]--;
//                 else return false;
//             }
//             else 
//                 return false;
//         }
//         return true;
//     }
// };