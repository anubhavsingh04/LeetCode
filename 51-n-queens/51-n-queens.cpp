// har column me queen rakh rakh ke check kr lo
// same row me na ho 
// same colmn me na ho 
// same digonal me na ho 
// agr ham queen left to right fill kr rhe hain to queen to left me chek kro 
// so no need to check for right
// to check 
// har bar ek colm me ek queen place kr ke ham aage badh ja rhe means we will not place two Q
// so no need to check for colm


class Solution {
public:
    // void addsoln(vector<string>&board,vector<vector<string>>&ans,int n)
    // {
    //     vector<string>tmp(n);
    //     for(int i=0;i<n;i++)
    //     {
    //         for(int j=0;j<n;j++)
    //         {
    //             tmp[i][j]=board[i][j];
    //         }
    //     }
    //     ans.push_back(tmp);
    // }
    
    bool issafe(int row,int col,vector<string>&board,int n)
    {   
        int x=row;
        int y=col;
        // check for left
        while(y>=0)
        {
            if(board[x][y]=='Q')
                return false;
            y--;
        }
        // check for digonal 
        x=row;
        y=col;
        while(x>=0 && y>=0)
        {
            if(board[x][y]=='Q')
                return false;
            x--;
            y--;
        }
        
         // check for digonal 
        x=row;
        y=col;
        while(x<n && y>=0)
        {
            if(board[x][y]=='Q')
                return false;
            x++;
            y--;
        }
        return true;
    }
    
    void solve(vector<string>&board,vector<vector<string>>&ans,int n,int col)
    {
        // base case 
        if(col==n)
        {
            ans.push_back(board);
            // addsoln(board,ans,n);
            return;
        }
        // pehle colm me har jgh rkh ke check kr lo baki recursion sambhal lega 
        for(int row=0;row<n;row++)
        {
            if(issafe(row,col,board,n))
            {
                board[row][col]='Q';
                solve(board,ans,n,col+1);
                board[row][col]='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>>ans;
        vector<string>board(n,string(n,'.'));
        int col=0;
        
        solve(board,ans,n,col);
        return ans;
        
    }
};







// class Solution {
// public:
//     vector<vector<string>> ret;
//     bool is_valid(vector<string> &board, int row, int col){
//         // check col
//         for(int i=row;i>=0;--i)
//             if(board[i][col] == 'Q') return false;
//         // check left diagonal
//         for(int i=row,j=col;i>=0&&j>=0;--i,--j)
//             if(board[i][j] == 'Q') return false;
//         //check right diagonal
//         for(int i=row,j=col;i>=0&&j<board.size();--i,++j)
//             if(board[i][j] == 'Q') return false;
//         return true;
//     }
//     void dfs(vector<string> &board, int row){
//         // exit condition
//         if(row == board.size()){
//             ret.push_back(board);
//             return;
//         }
//         // iterate every possible position
//         for(int i=0;i<board.size();++i){
//             if(is_valid(board,row,i)){
//                 // make decision
//                 board[row][i] = 'Q';
//                 // next iteration
//                 dfs(board,row+1);
//                 // back-tracking
//                 board[row][i] = '.';
//             }
//         }
//     }
//     vector<vector<string>> solveNQueens(int n) {
// 		// return empty if n <= 0
//         if(n <= 0) return {{}};
//         vector<string> board(n,string(n,'.'));
//         dfs(board,0);
//         return ret;
//     }
// };