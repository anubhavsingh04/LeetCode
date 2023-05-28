class Solution {
public:
    bool ispalindrome(string s,int i,int j)
    {
        while(i<j) 
        {
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
    
    void rec(int idx,string s,vector<string>v,vector<vector<string>>&ans)
    {
        if(idx>=s.size()){
            ans.push_back(v);
            return ;
        }
        for(int i=idx;i<s.size();i++)
        {
            if(ispalindrome(s,idx,i)){
                v.push_back(s.substr(idx,i-idx+1));
                rec(i+1,s,v,ans);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>v;
        rec(0,s,v,ans);
        return ans;
    }
};