class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int>ans;
        for(int i=0;i<ops.size();i++)
        {
            if(ops[i]=="C")
                ans.pop_back();
            else if(ops[i]=="D")
            {
                int x=ans.back();
                ans.push_back(2*x);
            }
            else if(ops[i]=="+")
            {
                int n=ans.size();
                int x=ans[n-1]+ans[n-2];
                ans.push_back(x);
            }
            else 
                ans.push_back(stoi(ops[i]));
        }
        int sum=0;
        for(int i=0;i<ans.size();i++)
        {
            sum+=ans[i];
        }
        return sum;
    }
};