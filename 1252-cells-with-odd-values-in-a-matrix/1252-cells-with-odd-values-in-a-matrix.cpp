class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<int>row(m,0),col(n,0);
        for(int i=0;i<indices.size();i++)
        {
            int r=indices[i][0];
            int c=indices[i][1];
            row[r]++;
            col[c]++;
        }
        int oddcnt=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if((row[i]+col[j])&1)
                    oddcnt++;
            }
        }
        return oddcnt;
    }
};