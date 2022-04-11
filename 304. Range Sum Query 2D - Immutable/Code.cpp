class NumMatrix {
public: 
    vector<vector<int>>pfs;
    NumMatrix(vector<vector<int>>& matrix) {
		// vector<vector<int>>pfs;
        int n=matrix.size();
        int m=matrix[0].size();
        pfs.resize(n+1,vector<int>(m+1));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                pfs[i][j]=matrix[i-1][j-1]+pfs[i][j-1]+pfs[i-1][j]-pfs[i-1][j-1];
            }
        }
    }    
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        ++row1;++col1;++row2;++col2; //since we are using 1 based pfs 
        return pfs[row2][col2]-pfs[row1-1][col2]-pfs[row2][col1-1]+pfs[row1-1][col1-1];
    }
};



// class NumMatrix {
//     vector<vector<int> > prefixsum;
// public:    
//     NumMatrix(vector<vector<int>>& matrix) : prefixsum(matrix) {
// 		for(auto& row : prefixsum) 
//             for(int i = 1; i < size(row); i++) 
//                 row[i] += row[i - 1];                
//     }    
    
//     int sumRegion(int row1, int col1, int row2, int col2) {
//         int sum = 0;
		
//         for(int row = row1; row <= row2; row++) 
//             sum += prefixsum[row][col2] - (col1 ? prefixsum[row][col1 - 1] : 0);
//         return sum;
//     }
// };

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */