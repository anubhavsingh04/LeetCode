CODE 1:

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n=mat.size();
        int m=mat[0].size();
        int total=n*m,cnt=0;
        if(r*c!=total)
            return mat;
        vector<vector<int>>ans;
        vector<int>v;
        int k=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                v.push_back(mat[i][j]);
                cnt++;
                if(cnt==c)
                {
                    cnt=0;
                    ans.push_back(v);
                    v.clear();
                }
            }
        }
        return ans;
    }
};

CODE 2:

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = size(mat), n = size(mat[0]), total = m * n;
        if(r * c != total) return mat;
        vector<vector<int>> ans(r, vector<int>(c));
        for(int i = 0; i < total; i++) 
            ans[i / c][i % c] = mat[i / n][i % n];
        return ans;
    }
};