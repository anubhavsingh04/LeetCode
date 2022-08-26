// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         for(int i  = 0; i<matrix.size(); ++i)
//         {
//             for(int j = 0; j<matrix[0].size(); ++j)
//             {
//                 if(matrix[i][j] == target)
//                     return true;
//             }
//         }
//         return false;
//     }
// };

// BInary search implementation
// A n * m matrix converted into an array: matrix[x][y] : a[x * m + y]
// An array can be converted into n * m matrix: a[x] : matrix[x / m][x % m]

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        if(n == 0 || m == 0)
            return false;
        
// matrix converted into array---> [0..n*m]
        int start = 0, end = m*n - 1;    
        while(start <= end)
        {
            int mid = start + (end - start) / 2;
			// a[x] : matrix[x / m][x % m] formulae
            int ind = matrix[mid/m][mid%m];
            if (target == ind)
                return true;
            else if(target < ind)
                end = mid - 1;
            else
                start = mid + 1;       
        }
        return false;
    }
};