// Using map

class Solution {
public:
    string sortString(string s) {
        vector<int>v(26,0);
        string ans="";
        int n=s.size();
        map<char,int>m;
        for(int i=0;i<s.size();i++)
        {
            m[s[i]]++;
        }
        while(n)
        {
            for(auto it=m.begin();it!=m.end();it++)
            {
                if(it->second!=0)
                {
                    ans+=it->first;
                    it->second--;
                    n--;
                }
            }
            for(auto it=m.rbegin();it!=m.rend();it++)
            {
                if(it->second!=0)
                {
                    ans+=it->first;
                    it->second--;
                    n--;
                }
            }
        }
        return ans;
    }
};







// class Solution {
// public:
//     string sortString(string s) {
//         vector<int>v(26,0);
//         string ans="";
//         int cnt=0;
//         for(auto &i:s)
//         {
//             v[i-'a']++;
//             cnt++;
//         }
//         while(cnt)
//         {
//             for(int i=0;i<26;i++)
//             {
//                 if(v[i]>0)
//                 {
//                     ans+=i+'a';
//                     cnt--;
//                     v[i]--;
//                 }
//             }
//             for(int i=25;i>=0;i--)
//             {
//                 if(v[i]>0)
//                 {
//                     ans+=i+'a';
//                     cnt--;
//                     v[i]--;
//                 }
//             }
//         }
//         return ans;
//     }
// };