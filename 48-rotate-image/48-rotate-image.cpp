 // for 90 degree: Take Transpose then swap columns 
 // for 180 degree: Swap columns then swap rows
 // for 270 degree: Take transpose then swap rows
 // for taking transpose upper loop 0 to mat.size
 // inner loop will run from i to mat.size then swap(mat[i][j],mat[j][i])
// 00 with 0 m-1  then 01 with 0 m-2
class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n=mat.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                swap(mat[i][j],mat[j][i]);
            }
        }
        
        for(int i=0;i<n;i++)
        {
            int start=0,end=n-1;
            while(start<end)
            {
                swap(mat[i][start],mat[i][end]);
                start++,end--;
            }
        }
    }
};