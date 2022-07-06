class Solution {
public:
    bool isvalid(vector<vector<int>>&image,int i,int j,int color,int newcolor)
    {
        if(i>=0 && i<image.size()&&j>=0 && j<image[0].size()&& image[i][j]==color)
            return true;
        return false;
    }
    void dfs(vector<vector<int>>& image, int i, int j,int color, int newcolor)
    {
        if(color==newcolor)
            return;
        image[i][j]=newcolor;
        if(isvalid(image,i+1,j,color,newcolor))
        {
            dfs(image,i+1,j,color,newcolor);
        }
        
        if(isvalid(image,i-1,j,color,newcolor))
        {
            dfs(image,i-1,j,color,newcolor);
        }
        if(isvalid(image,i,j+1,color,newcolor))
        {
            dfs(image,i,j+1,color,newcolor);
        }
        if(isvalid(image,i,j-1,color,newcolor))
        {
            dfs(image,i,j-1,color,newcolor);
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
    {
        int color=image[sr][sc];
        
        dfs(image,sr,sc,color,newColor);
        return image;
    }
};








// class Solution {
// public:
    
//     void dfs(vector<vector<int>>& image, int i, int j,int val, int newColor)
//     {
//         if(i<0 || i>=image.size() || j<0 || j>= image[0].size() || image[i][j] == newColor || image[i][j] != val)
//         {
//             return;
//         }
//         image[i][j] = newColor;
//         dfs(image,i-1,j,val,newColor);
//         dfs(image,i+1,j,val,newColor);
//         dfs(image,i,j-1,val,newColor);
//         dfs(image,i,j+1,val,newColor);
//     }
    
//     vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
//     {
//         int val = image[sr][sc];
//         dfs(image,sr,sc,val,newColor);
//         return image;
//     }
// };