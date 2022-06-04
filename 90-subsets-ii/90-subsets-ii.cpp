class Solution {
public:
    vector<vector<int>>v;
    set<vector<int>>st;
    void solve(vector<int> ip,vector<int>op)
    {
        if(ip.size()==0)
        {
            sort(op.begin(),op.end());
            st.insert(op);
            return ;
        }
        vector<int>op1=op;
        vector<int>op2=op;
        op2.push_back(ip[0]);
        ip.erase(ip.begin()+0);
        solve(ip,op1);
        solve(ip,op2);
        return ;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>op;
        solve(nums,op);
        for(auto &i:st){
            v.push_back(i);
        }
        return v;
    }
};