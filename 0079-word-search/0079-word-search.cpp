class Solution {
public:
    bool dfs(vector<vector<char>>& board,int i,int j,int n,int m, string word,int idx)
    {
        if(idx>=word.size()) return true ;
        if(i<0 || i>=n || j<0 || j>=m||board[i][j]!=word[idx]) return false;
        char ch=board[i][j];
        board[i][j]='*';
        bool left=dfs(board,i,j-1,n,m,word,idx+1);
        bool right=dfs(board,i,j+1,n,m,word,idx+1);
        bool up=dfs(board,i-1,j,n,m,word,idx+1);
        bool down=dfs(board,i+1,j,n,m,word,idx+1);
        board[i][j]=ch;
        return left||right||up||down;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0])
                {
                    if(dfs(board,i,j,n,m,word,0)) return true;
                }
            }
        }
        return false;
    }
};