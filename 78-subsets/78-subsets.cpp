class Solution {
public:
    vector<vector<int>>v;
    vector<vector<int>>solve(vector<int> ip,vector<int>op)
    {
        if(ip.size()==0)
        {
            v.push_back(op);
            return v;
        }
        vector<int>op1=op;
        vector<int>op2=op;
        op2.push_back(ip[0]);
        ip.erase(ip.begin()+0);
        solve(ip,op1);
        solve(ip,op2);
        return v;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>op={};
        return solve(nums,op);
    }
};