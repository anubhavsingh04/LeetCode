class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n=words.size();
        int m=words[0].size();
        vector<int>ans;
        if(m*n>s.size()) return ans;
        for(int i=0;i<=s.size()-m*n;i++)
        {
            unordered_map<string,int>mp;
            for(int j=0;j<n;j++)
            {
                mp[words[j]]++;
            }
            int t;
            for(t=0;t<n;t++)
            {
                string str = s.substr(i+t*m,m);
                
                if(mp.count(str)==0) 
                    break;
                else
                {
                    if(mp[str]!=0)
                        mp[str]--;
                    else 
                        break;
                }
            }
            if(t==n)
                ans.push_back(i);
        }
        return ans;
    }
};



// class Solution {
// public:
//     bool checkSubstring(unordered_map<string, int> wordCount, string s, int wordLen) {
//         for(int j=0; j<s.size(); j+=wordLen) {
//             string w = s.substr(j, wordLen);
//             if(wordCount.find(w) != wordCount.end()) {
//                 if(--wordCount[w] == -1) {
//                     return false;
//                 }
//             } else {
//                 return false;
//             }
//         }
//         return true;
//     }

//     vector<int> findSubstring(string s, vector<string>& words) {
//         vector<int> res;
//         int wordLen = words[0].size();
//         int sLen = s.size();
//         int wordsWindow = words.size() * wordLen;
        
//         unordered_map<string, int> wordCount;
//         for(int i=0; i<words.size(); i++) {
//             wordCount[words[i]]++;
//         }
        
//         int i = 0;
//         while(i + wordsWindow <= sLen) {
//             if(checkSubstring(wordCount, s.substr(i, wordsWindow), wordLen)) {
//                 res.push_back(i);
//             }
//             i++;
//         }
//         return res;
//     }
// };