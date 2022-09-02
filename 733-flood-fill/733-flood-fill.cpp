class Solution {
public: 
    void dfs(int i,int j,vector<vector<int>>&image,int inicolor,int newcolor)
    {
        if(i<0||i>=image.size()||j<0||j>=image[0].size()||image[i][j]==newcolor||image[i][j]!=inicolor)
        {
            return;
        }
        image[i][j]=newcolor;
        dfs(i+1,j,image,inicolor,newcolor);
        dfs(i-1,j,image,inicolor,newcolor);
        dfs(i,j-1,image,inicolor,newcolor);
        dfs(i,j+1,image,inicolor,newcolor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newcolor)
    {
        int inicolor=image[sr][sc];
        dfs(sr,sc,image,inicolor,newcolor);
        return image;
    }
};


// class Solution {
// public: 
//     bool isValid(int newrow,int newcol,int n,int m,vector<vector<int>>& image,
//                  vector<vector<int>>& ans,int inicolor,int newcolor)
//     {
//         if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && 
//           image[newrow][newcol]==inicolor && ans[newrow][newcol]!=newcolor)
//         {
//             return true;
//         }
//         return false;
//     }
//     void dfs(int sr,int sc,vector<vector<int>>& image,vector<vector<int>>& ans,int inicolor,int newcolor,
//             int delrow[],int delcol[])
//     {
//         ans[sr][sc]=newcolor;
//         int n=image.size();
//         int m=image[0].size();
//         for(int i=0;i<4;i++)
//         {
//             int newrow=sr+delrow[i];
//             int newcol=sc+delcol[i];
//             if(isValid(newrow,newcol,n,m,image,ans,inicolor,newcolor))
//             {
//                 dfs(newrow,newcol,image,ans,inicolor,newcolor,delrow,delcol);
//             }
//         }
//     }
//     vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newcolor)
//     {
//         int inicolor=image[sr][sc];
//         vector<vector<int>>ans=image;
//         int delrow[]={-1,0,1,0};
//         int delcol[]={0,1,0,-1};
//         dfs(sr,sc,image,ans,inicolor,newcolor,delrow,delcol);
//         return ans;
//     }
// };




// class Solution {
// public:
//     bool isvalid(vector<vector<int>>&image,int i,int j,int color,int newcolor)
//     {
//         if(i>=0 && i<image.size()&&j>=0 && j<image[0].size()&& image[i][j]==color)
//             return true;
//         return false;
//     }
//     void dfs(vector<vector<int>>& image, int i, int j,int color, int newcolor)
//     {
//         if(color==newcolor)
//             return;
//         image[i][j]=newcolor;
//         if(isvalid(image,i+1,j,color,newcolor))
//         {
//             dfs(image,i+1,j,color,newcolor);
//         }
        
//         if(isvalid(image,i-1,j,color,newcolor))
//         {
//             dfs(image,i-1,j,color,newcolor);
//         }
//         if(isvalid(image,i,j+1,color,newcolor))
//         {
//             dfs(image,i,j+1,color,newcolor);
//         }
//         if(isvalid(image,i,j-1,color,newcolor))
//         {
//             dfs(image,i,j-1,color,newcolor);
//         }
//     }
    
//     vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
//     {
//         int color=image[sr][sc];
        
//         dfs(image,sr,sc,color,newColor);
//         return image;
//     }
// };








// class Solution {
// public:
    
//     void dfs(vector<vector<int>>& image, int i, int j,int val, int newColor)
//     {
//         if(i<0 || i>=image.size() || j<0 || j>= image[0].size() ||
//             image[i][j] == newColor || image[i][j] != val)
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