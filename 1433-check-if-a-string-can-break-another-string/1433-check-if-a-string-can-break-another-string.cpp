class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        int n=s1.size();
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        bool s1canbreaks2=true;
        bool s2canbreakss1=true;
        for(int i=0;i<n;i++)
        {
            if(s1[i]<s2[i])
                s1canbreaks2=false;
            if(s2[i]<s1[i]) 
                s2canbreakss1=false;
        }
        if(s1canbreaks2 || s2canbreakss1) return true;
        else return false;
    }
};




// class Solution {
// public:
//     bool canbreak(string &a,string &b)
//     {
//         int n=a.size();
//         int cnt1=0,cnt2=0;
//         for(int i=0;i<n;i++)
//         {
//             if(a[i]>=b[i])
//                 cnt1++;
//         }
//         for(int i=0;i<n;i++)
//         {
//             if(b[i]>=a[i])
//                 cnt2++;
//         }
//         return cnt1==n || cnt2==n;
//     }
//     bool checkIfCanBreak(string s1, string s2) {
//         int n=s1.size();
//         sort(s1.begin(),s1.end());
//         sort(s2.begin(),s2.end());
        
//         if(canbreak(s1,s2)) return true;
//         return false;
        
//     }
// };