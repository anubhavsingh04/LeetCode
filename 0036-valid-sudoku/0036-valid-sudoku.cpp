// Without extra space 
// here for each  81 cells we will check the curr character is valid or not 
// here for each cells firstly we will remove the character and assign board[i][j]='.' 
// after this we will just check if this character can be assigned at that position or not 
// if it can not be assigned then return false else return true

class Solution {
public:
    bool isvalid(vector<vector<char>>&board,char ch,int row,int col)
    {
        for(int i=0;i<9;i++)
        {
            if(board[row][i]==ch) return false;
            if(board[i][col]==ch) return false;
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==ch) return false;
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.') continue;
                
                char ch=board[i][j];
                board[i][j]='.';
                
                if(!isvalid(board,ch,i,j)) return false;
                else {
                    board[i][j]=ch;
                }
            }
        }
        return true;
    }
};

// make 9 sets of row ,col ,block 
// if the curr character is already there in row or col or block then we cant insert ch in that pos
// so return false otherwise insert it into row ,col and block 


// class Solution {
// public:
//     bool isValidSudoku(vector<vector<char>>& board) {
//         vector<set<char>>row(9),col(9),block(9);
//         for(int i=0;i<9;i++)
//         {
//             for(int j=0;j<9;j++)
//             {
//                 if(board[i][j]=='.') continue;
                
//                 char ch=board[i][j];
//                 if(row[i].count(ch) || col[j].count(ch) || block[3*(i/3)+j/3].count(ch))
//                     return false;
//                 row[i].insert(ch);
//                 col[j].insert(ch);
//                 block[3*(i/3)+j/3].insert(ch);
//             }
//         }
//         return true;
//     }
// };
