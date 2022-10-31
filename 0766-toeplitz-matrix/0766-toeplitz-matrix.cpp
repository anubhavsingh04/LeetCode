class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int i=0,j=0;
        int n=matrix.size();
        int m=matrix[0].size();
        while(i<n-1)
        {
            j=0;
            while(j<m-1)
            {
                if(matrix[i][j]!=matrix[i+1][j+1]) return false;
                j++;
            }
            i++;
        }
        return true;
    }
};