// In for loop we have pushed n integer 1 integer is remaining 
// after coming out of the for loop value of  start and end will be equal so push any of them

class Solution{
public:
    vector<int> diStringMatch(string s){
        vector<int>ans;
        int start=0,end=s.size();
        for(int i=0;i<=s.size();i++)
        {
            if(s[i]=='I')
                ans.push_back(start++);
            else 
                ans.push_back(end--);
        }
        // ans.push_back(start++);
        return ans;
    }
};



// class Solution {
// public:
//     vector<int> diStringMatch(string s) {
//         int l=0,r=s.size();
//         vector<int>ans;
//         for(auto &i:s)
//         {
//             if(i=='D') ans.push_back(r--);
//             else ans.push_back(l++);
//         }
//         ans.push_back(l++);
//         return ans;
//     }
// };

// class Solution{
// public:
//     vector<int> diStringMatch(string s){
//         int a=0,b=s.size();
//         vector<int>ans;
//         for(auto &i:s)
//         {
//             if(i=='I') ans.push_back(a++);
//             else if(i=='D') ans.push_back(b--);
//         }
//         if(s[s.size()-1]=='D') ans.push_back(b--);
//         if(s[s.size()-1]=='I') ans.push_back(a++);
//         return ans;    
//     }
// };