// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int n=matrix.size(),m=matrix[0].size();
//         int low=0,high=m*n-1;
//         while(low<=high)
//         {
//             int mid=(low+(high-low)/2);
//             int row=mid/m;
//             int col=mid%m;
//             if(matrix[row][col]==target) return true;
//             else if(matrix[row][col]<target) low=mid+1;
//             else high=mid-1;
//         }
//         return false;
//     }
// };



class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size();
        int i=0,j=m-1;
        int low=0,high=m*n-1;
        while(i<n && j>=0)
        {
            int mid=(low+(high-low)/2);
            if(matrix[i][j]>target) j--;
            else if(matrix[i][j]<target) i++;
            else return true;
        }
        return false;
    }
};