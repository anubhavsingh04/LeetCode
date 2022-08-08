// Traverse the matrix 
// Take two vector to mark the rows and column in which the entry is 0
// finally mark matrix[i][j] is 0 if either of the row[i] or column[i] is 0  

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>row(n,-1);
        vector<int>col(m,-1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    row[i]=0; // marking that row in which element is zero
                    col[j]=0; // marking that col in which element is x=zero
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(row[i]==0||col[j]==0)
                    matrix[i][j]=0;
            }
        }
    }
};