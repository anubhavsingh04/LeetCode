// ith ow have i+1 elements 
class Solution {
public:
    vector<vector<int>> generate(int rows) {
        vector<vector<int>>ans;
        for(int i=0;i<rows;i++)
        {
            vector<int>row(i+1,1);
            for(int j=1;j<i;j++)
            {
                row[j]=ans[i-1][j-1]+ans[i-1][j];
            }
            ans.push_back(row);
        }
        return ans;
    }
};