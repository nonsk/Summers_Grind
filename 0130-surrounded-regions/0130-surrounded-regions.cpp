class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& board) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != 'O') {
            return;
        }
        
        // Mark as visited with a temporary character
        board[i][j] = 'T';
        
        vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        for (auto [dx, dy] : dir) {
            dfs(i + dx, j + dy, board);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        
        int rows = board.size();
        int cols = board[0].size();
        
        // Run DFS from all border cells
        for (int i = 0; i < rows; i++) {
            if (board[i][0] == 'O') dfs(i, 0, board);
            if (board[i][cols-1] == 'O') dfs(i, cols-1, board);
        }
        
        for (int j = 0; j < cols; j++) {
            if (board[0][j] == 'O') dfs(0, j, board);
            if (board[rows-1][j] == 'O') dfs(rows-1, j, board);
        }
        
        // Convert remaining 'O's to 'X's and restore 'T's to 'O's
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'T') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};