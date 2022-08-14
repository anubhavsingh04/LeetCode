// class Solution {
// public:
//     string smallestNumber(string pattern) {
//         int n=pattern.size();
//         string ans;
//         stack<int>st;
//         for(int i=0;i<=n;i++)
//         {
//             st.push(i+1);
//             if(pattern[i]=='I' || i==n)
//             {
//                 while(!st.empty())
//                 {
//                     ans+=to_string(st.top());
//                     st.pop();
//                 }
//             }
//         }
//         return ans;
//     }
// };


// Using hints given in the question

class Solution {
public:
    bool isvalid(string &str,string &pattern)
    {
        for(int i=0;i<pattern.size();i++)
        {
            if((str[i]<str[i+1] && pattern[i]=='D') || (str[i]>str[i+1] && pattern[i]=='I'))
                return false;
        }
        return true;
    }
    string smallestNumber(string pattern) {
        int n=pattern.size();
        string s="123456789";
        int sz=n+1;
        do{
            string str=s.substr(0,sz);
            if(isvalid(str,pattern))
                return str;
        }while(next_permutation(s.begin(),s.end()));
        return "";
    }
};