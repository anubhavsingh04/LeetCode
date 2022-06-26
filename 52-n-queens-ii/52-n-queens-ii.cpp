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
    
    void solve(vector<string>&board,int &ans,int n,int col)
    {
        // base case 
        if(col==n)
        {
            ans++;
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
    
    int totalNQueens(int n) {
		int ans=0;
        vector<string>board(n,string(n,'.'));
        int col=0;
        
        solve(board,ans,n,col);
        return ans;
        
    }
};






// class Solution {
// public:
//         int totalNQueens(int n) {
//         vector<vector<bool>> board(n, vector<bool>(n, false));
//         return solve(board, 0);
//     }
//     bool check(vector<vector<bool>>& board, int row, int col) {
//         int n = size(board);
//         for(int i = 0; i <= row; i++) {
//             if(board[i][col]) return false; // checking if any queen already placed on same column previously
//             // checking if all diagonals are safe -
//             if(row - i >= 0 && col - i >= 0 && board[row - i][col - i]) return false;
//             if(row - i >= 0 && col + i <  n && board[row - i][col + i]) return false;
//         }
//         return true;
//     }    
//     int solve(vector<vector<bool>>& board, int row) {
//         if(row == size(board)) return 1;
//         int count = 0;
//         for(int col = 0; col < size(board); col++)           
//             if(check(board, row, col)){          // check if we can place at (row, col)
//                 board[row][col] = true;          // place the queen at (row, col)
//                 count += solve(board, row + 1);  // explore for the next row. The function will return 1 if all N queens get placed for current combination
//                 board[row][col] = false;         // backtrack - remove previously placed queen and try for different columns
//             }                                
//         return count;
//     }
// };





// class Solution {
// public:
//         int totalNQueens(int n) {
// 	vector<bool> col(n), diag(2*n-1), anti_diag(2*n-1);
// 	return solve(col, diag, anti_diag, 0);
// }
   
// int solve(vector<bool>& col, vector<bool>& diag, vector<bool>& anti_diag, int row) {
// 	int n = size(col), count = 0;
//     if(row == n) return 1;
// 	for(int column = 0; column < n; column++)           
// 		if(!col[column] && !diag[row + column] && !anti_diag[row - column + n - 1]){        // check if (row, column) is safe
// 			col[column] = diag[row + column] = anti_diag[row - column + n - 1] = true;      // place at (row, column)
// 			count += solve(col, diag, anti_diag, row + 1);                                  // explore for the next row
// 			col[column] = diag[row + column] = anti_diag[row - column + n - 1] = false;     // backtrack
// 		}                                
// 	return count;
// }
// };

