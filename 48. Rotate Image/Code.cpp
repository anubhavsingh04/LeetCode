class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=i;j<matrix.size();j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<matrix.size();i++)
        {
            int s=0,e=matrix.size()-1;
            while(s<e)
            {
                swap(matrix[i][s],matrix[i][e]);
                s++;
                e--;
            }
        }
    }
};