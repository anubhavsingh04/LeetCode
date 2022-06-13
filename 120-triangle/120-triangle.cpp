class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int minSum = INT_MAX;
          int h=triangle.size(),j;
         j=h;
        vector<vector<int>> v(h,vector<int> (j,0));
         v[0][0]=triangle[0][0];
         for(int i=1;i<h;i++)
         {
             for(int j=0;j<triangle[i].size();j++)
             {
                 if(j==0) v[i][j]=v[i-1][j]+triangle[i][j];
                 else if(j==triangle[i].size()-1) v[i][j]=v[i-1][j-1]+triangle[i][j];
                 else
                 v[i][j]=min(v[i-1][j-1],v[i-1][j])+triangle[i][j];
             }
              
         }
         
        return *min_element(v[h-1].begin(),v[h-1].end());
         
        
    }
};