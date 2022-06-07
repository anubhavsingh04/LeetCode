// class Solution {
// public:
//     vector<string>ans;
//     void func(int open,int close,int n,string curr)
//     {
//         if(curr.length()==n*2)
//         {
//             ans.push_back(curr);
//             return;
//         }
//         if(open<n) func(open+1,close,n,curr+"(");
//         if(close<open) func(open,close+1,n,curr+")");
//     }
//     vector<string> generateParenthesis(int n) {
//         func(0,0,n,"");
//         return ans;
//     }
// };

class Solution {
public:
    void solve(int open,int close,string op,vector<string>&ans){
        if(open==0&&close==0){
            ans.push_back(op);
            return;
        }
        if(open!=0){
            string op1=op;
            op1.push_back('(');
            solve(open-1,close,op1,ans);
        }
        if(close>open){
            string op2=op;
            op2.push_back(')');
            solve(open,close-1,op2,ans);
        }
        return ;
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        int open=n,close=n;
        string op="";
        solve(open,close,op,ans);
        return ans;
    }
};