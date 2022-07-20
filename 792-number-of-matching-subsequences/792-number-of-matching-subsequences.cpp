class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int k=s.size(),cnt=0;
        unordered_map<string,int>m;
        for(auto &i:words)
        {
            m[i]++;
        }
        for(auto &i:m)
        {
            string curr=i.first;
            int curr_sz=curr.size();
            int start1=0,start2=0;
            while(start1<k && start2<curr_sz)
            {
                if(s[start1]==curr[start2])
                    start1++,start2++;
                else 
                    start1++;
            }
            if(start2==curr_sz)
                cnt+=i.second;
        }
        return cnt;
    }
};








// Brute force gives tle 
// class Solution {
// public:
//     int numMatchingSubseq(string s, vector<string>& words) {
//         int k=s.size();
//         int cnt=0;
//         for(int i=0;i<words.size();i++)
//         {
//             string curr=words[i];
//             int curr_size=curr.size();
//             int start1=0,start2=0;
//             while(start1<k && start2<curr_size)
//             {
//                 if(s[start1]==curr[start2])
//                 {
//                     start1++,start2++;
//                 }
//                 else
//                 {
//                     start1++;
//                 }
//             }
//             if(start2==curr_size)
//                 cnt++;
//         }
//         return cnt;
//     }
// };