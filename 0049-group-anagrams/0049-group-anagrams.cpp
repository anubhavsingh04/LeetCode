// Anagram are the list of words whose freq_map (count of character in a particular string) are same 
// for eg we have strs = ["eat","tea","tan","ate","nat","bat"]
// now freq_map will be: 
//1. eat --> a1e1t1
//2. tea --> a1e1t1
//3. tan--> a1n1t1
//4. ate--> a1e1t1
//5. nat --> a1n1t1
//6. bat --> a1b1t1
// means string at 1,2,4 (i.e. "eat","tea","ate") will fall under freq_map a1n1t1
// so make a map of freq_map and vector of string because we need to store the string having same freq_map in a same vector 

// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         map<map<char,int>,vector<string>>mp;
//         for(auto &str:strs)
//         {
//             map<char,int>freq_map;
//             for(auto &ch:str)
//             {
//                 freq_map[ch]++;
//             }
//             if(mp.find(freq_map)==mp.end())
//             {
//                 vector<string>v;
//                 v.push_back(str);
//                 mp[freq_map]=v;
//             }
//             else 
//             {
//                 mp[freq_map].push_back(str);
//             }
//         }
//         vector<vector<string>>ans;
//         for(auto i:mp)
//         {
//             ans.push_back(i.second);
//         }
//         return ans;
//     }
// };


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.size()==1) {
            return {{strs[0]}};
        }
        unordered_map<string,vector<string>>mp;
        for(auto &str:strs)
        {
            string tmp=str;
            sort(tmp.begin(),tmp.end());
            mp[tmp].push_back(str);
        }
        vector<vector<string>>ans;
        for(auto &i:mp)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};
