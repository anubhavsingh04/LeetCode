class Solution {
public:
    void solve(string digits, int idx, vector<string>&ans,string op ,unordered_map<char,string>&m)
    {
        if(idx>=digits.size())
        {
            ans.push_back(op);
        }
        string s=m[digits[idx]];
        for(int i=0;i<s.size();i++)
        {
            op.push_back(s[i]);
            solve(digits,idx+1,ans,op,m);
            op.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string>m={{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},
                          {'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
        vector<string> ans;
        if(digits.empty())
            return ans;
        int idx=0;
        string op="";
        solve(digits,idx,ans,op,m);
        return ans;
    }
};