class Solution {
public:
    string solve(string s)
    {
        stack<char>st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='#'&&!st.empty())
            {
                st.pop();
            }
            else if(s[i]!='#')
                st.push(s[i]);
        }
        string ans;
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
    bool backspaceCompare(string s, string t) {
       return solve(s)==solve(t);
    }
};

// class Solution {
// public:
//     bool backspaceCompare(string s, string t) {
//        stack<int>st1,st2;
//         string a,b;
//         for(int i=0;i<s.size();i++)
//         {
//             if(s[i]=='#'&&!st1.empty())
//                 st1.pop();
//                 else if(s[i]!='#')
//                     st1.push(s[i]);      
//         }
//         for(int i=0;i<t.size();i++)
//         {
//             if(t[i]=='#'&&!st2.empty())
//                 st2.pop();
//             else if(t[i]!='#')
//                 st2.push(t[i]);
//         }
//         while(!st1.empty())
//         {
//             a+=st1.top();
//             st1.pop();
//         }
//         while(!st2.empty())
//         {
//             b+=st2.top();
//             st2.pop();
//         }
//         return (a==b);
//     }
// };