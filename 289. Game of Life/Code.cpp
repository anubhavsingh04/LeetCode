class Solution {
public:
    int getliveneighbour(vector<vector<int>>&board,int i,int j,int rows,int column)
    {
        int cnt=0;
        // upper neighbour
        if(i>0)
        {
            if(board[i-1][j]==1||board[i-1][j]==3) 
                cnt++;
        }
        // lower neighbour
        if(i<rows-1)
        {
            if(board[i+1][j]==1||board[i+1][j]==3) 
                cnt++;
        }
        // Left neighbour
        if(j>0)
        {
            if(board[i][j-1]==1||board[i][j-1]==3) 
                cnt++;
        }
        // Right neighbour
        if(j<column-1)
        {
            if(board[i][j+1]==1||board[i][j+1]==3) 
                cnt++;
        }
        // digonal north east i-1,j-1
        if(i>0&&j>0)
        {
            if(board[i-1][j-1]==1||board[i-1][j-1]==3) 
                cnt++;
        }
        // digonal soth west i+1,j+1
        if(i<rows-1&&j<column-1)
        {
            if(board[i+1][j+1]==1||board[i+1][j+1]==3) 
                cnt++;
        }
         // digonal south east i+1,j-1     
        if(i<rows-1&&j>0)
        {
            if(board[i+1][j-1]==1||board[i+1][j-1]==3) 
                cnt++;
        }
         //digonal north west i-1,j+1     
        if(i>0&&j<column-1)
        {
            if(board[i-1][j+1]==1||board[i-1][j+1]==3) 
                cnt++;
        }
         return cnt;     
    }
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int liveCnt=getliveneighbour(board,i,j,m,n);
                // dead to live mark as 2 live to dead marks as 3
                if(board[i][j]==0)
                {
                    if(liveCnt==3)
                    board[i][j]=2;
                }
                else if(board[i][j]==1)
                {
                    if(liveCnt<2||liveCnt>3)
                    board[i][j]=3;
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==2)
                board[i][j]=1;
                else if(board[i][j]==3)
                board[i][j]=0;
            }
        }
    }
};