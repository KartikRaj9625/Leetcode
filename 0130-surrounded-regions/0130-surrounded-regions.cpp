// class Solution {
// public:
//     vector<int> x = {-1, 1, 0, 0};
//     vector<int> y = {0, 0, -1, 1};

//     void dfs(vector<vector<char>>& board, int i, int j) {
//         int n = board.size();
//         int m = board[0].size();

//         if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] != 'O')
//             return;
//         board[i][j] = '#'; // mark visited
//         for (int k = 0; k < x.size(); k++) {
//             dfs(board, i + x[k], j + y[k]);
//         }
//         return;
//     }
//     void solve(vector<vector<char>>& board) {
//         int n = board.size();
//         int m = board[0].size();

//         for (int i = 0; i < n; i++) {
//             if (board[i][0] == 'O') {
//                 dfs(board, i, 0);
//             }
//         }
//         for (int i = 0; i < n; i++) {
//             if (board[i][m - 1] == 'O') {
//                 dfs(board, i, m - 1);
//             }
//         }
//         for (int j = 0; j < m; j++) {
//             if (board[0][j] == 'O') {
//                 dfs(board, 0, j);
//             }
//         }
//         for (int j = 0; j < m; j++) {
//             if (board[n - 1][j] == 'O') {
//                 dfs(board, n - 1, j);
//             }
//         }
//         for (int i = 0; i < n; i++) {

//             for (int j = 0; j < m; j++) {

//                 if (board[i][j] == '#')
//                     board[i][j] = 'O';

//                 else if (board[i][j] == 'O')
//                     board[i][j] = 'X';
//             }
//         }
//     }
// };

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        int n = board.size();
        int m = board[0].size();
        queue<pair<int, int>> q;
        vector<int> x = {-1, 1, 0, 0};
        vector<int> y = {0, 0, -1, 1};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) &&
                    board[i][j] == 'O') {
                    q.push({i, j});
                    board[i][j] = '#';
                }
                while (!q.empty()) {
                    auto [i, j] = q.front();
                    q.pop();

                    for (int k = 0; k < x.size(); k++) {
                        int row = i + x[k];
                        int col = j + y[k];

                        if (row >= 0 && row < n && col >= 0 && col < m &&
                            board[row][col] == 'O') {
                            q.push({row,col});
                            board[row][col] = '#';
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == '#') {
                    board[i][j] = 'O';
                } else {
                    board[i][j] = 'X';
                }
            }
        }
    }
};