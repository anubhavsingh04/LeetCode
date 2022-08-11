// make 9 sets of row ,col ,block 
// if the curr character is already there in row or col or block then we cant insert ch in that pos
// so return false otherwise insert it into row ,col and block 


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<char>>row(9),col(9),block(9);
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.') continue;
                
                char ch=board[i][j];
                if(row[i].count(ch) || col[j].count(ch) || block[3*(i/3)+j/3].count(ch))
                    return false;
                row[i].insert(ch);
                col[j].insert(ch);
                block[3*(i/3)+j/3].insert(ch);
            }
        }
        return true;
    }
};