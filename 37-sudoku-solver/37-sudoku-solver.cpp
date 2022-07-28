// each row have digits from 1-9 exactly once  
// each col have digits from 1-9 exactly once  
// each 3 X 3 matrix have digits from 1-9 exactly once  
// Try every possible positon to fill each the empty places and 
// for each empty place multiple recursion call will be made 
// let say we have filled some empty cell with some numbr and next recursion is called 
// for the next empty cell but if we are unable to fill this empty cell then we will return false from // here and it will backtrack and reaches to the prev cell and check for another possibilty
// if possible to fill then return true otherwise  change the baord[i][j]='.'

// Checking whether a position is valid or not means first three conditons fullfilling or not 
// iterate single time from 1 to 9 and check if board[row][i]==ch or board[i][col]==ch or 
// board[3*(row/3)+i/3][3*(col/3)+i%3]==ch then return false else return true


class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve_suduko(board);
    }
    
    bool solve_suduko(vector<vector<char>>& board)
    {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='.')
                {
                    for(char ch='1';ch<='9';ch++)
                    {
                        if(isvalid(board,ch,i,j))
                        {
                            board[i][j]=ch;
                            if(solve_suduko(board)) return true;
                            else board[i][j]='.'; // backtarck if unable to fill the board
                        } 
                    }
                    return false;
                }
            }
        }
        return true; // if there is  no empty cell return true
    }
    
    bool isvalid(vector<vector<char>>& board,char ch,int row,int col)
    {
        for(int i=0;i<9;i++)
        {
            if(board[row][i]==ch) return false;
            if(board[i][col]==ch) return false;
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==ch) return false;
        }
        return true;
    }
};