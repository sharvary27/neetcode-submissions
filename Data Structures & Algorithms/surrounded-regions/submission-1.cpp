class Solution {
public:
    // input : "X" , "O" , Matrix
    //output : Matrix
    //approach : 1.dfs(convert all the boundary cells) 2. LinearScan to     convert back
    void dfs(int r, int c, vector<vector<char>>& board){
        if(r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] == 'X' || board[r][c] == 'A'){
            return ;
        }

        board[r][c] = 'A';

        dfs(r+1, c, board);
        dfs(r, c+1, board);
        dfs(r-1, c, board);
        dfs(r, c-1, board);
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        for(int i = 0 ; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 || i == n-1  || j == 0 || j == m-1){
                    if(board[i][j] == 'O'){
                        dfs(i, j, board);
                    }
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j <m; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }else if(board[i][j] == 'A'){
                    board[i][j] = 'O';
                }
            }
        }

    }
};
