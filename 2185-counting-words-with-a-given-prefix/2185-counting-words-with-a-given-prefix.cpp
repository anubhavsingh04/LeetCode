// class Solution {
// public:
//     int prefixCount(vector<string>& words, string pref) {
//         int cnt=0,k=0;
//         for(auto &word: words)
//         {
//             int n=pref.size();
//             if(word.substr(0,n)==pref)
//             cnt++;
//         }
//         return cnt;
//     }
// };


class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans=0;
        for(auto & word:words)
            if(word.find(pref)==0) // agr pref 0 index pe exist kr rhi h
                ans++;
        return ans;
    }
};