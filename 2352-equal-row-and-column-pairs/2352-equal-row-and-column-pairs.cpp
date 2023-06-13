class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        int ans=0;
        for(int row=0;row<n;row++)
        {
            for(int col=0;col<n;col++)
            {
                bool flag=true;
                for(int k=0;k<n;k++)
                {
                    if(grid[row][k]!=grid[k][col]){
                        flag=false;
                        break;
                    }
                }
                if(flag) ans++;
            }
        }
        return ans;
    }
};