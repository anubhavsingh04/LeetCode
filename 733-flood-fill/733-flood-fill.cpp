class Solution {
public:
    int delrow[4]={-1,0,1,0}; int delcol[4]={0,1,0,-1};
    void dfs(vector<vector<int>>&image,int i,int j,int inicolor,int newcolor)
    {
        if(i<0||i>=image.size()||j<0||j>=image[0].size()||image[i][j]==newcolor||image[i][j]!=inicolor)
        {
            return ;
        }
        image[i][j]=newcolor;
        for(int k=0;k<4;k++)
        {
            int newrow=i+delrow[k];
            int newcol=j+delcol[k];
            dfs(image,newrow,newcol,inicolor,newcolor);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int inicolor=image[sr][sc];
        dfs(image,sr,sc,inicolor,color);
        return image;
    }
};