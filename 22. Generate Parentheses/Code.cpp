class Solution {
public:
    vector<string>ans;
    void func(int open,int close,int n,string curr)
    {
        if(curr.length()==n*2)
        {
            ans.push_back(curr);
            return;
        }
        if(open<n) func(open+1,close,n,curr+"(");
        if(close<open) func(open,close+1,n,curr+")");
    }
    vector<string> generateParenthesis(int n) {
        func(0,0,n,"");
        return ans;
    }
};