class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty())
            return 0;
        queue<pair<int, int>> q;
        int res = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<int> x = {-1, 1, 0, 0};
        vector<int> y = {0, 0, -1, 1};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    q.push({i, j});
                    grid[i][j] = '0';
                    res++;
                }
                while (!q.empty()) {
                    auto [i, j] = q.front();
                    q.pop();
                    for (int k = 0; k < x.size(); k++) {
                        int row = i + x[k];
                        int col = j + y[k];
                        if (row >= 0 && row < n && col >= 0 && col < m &&
                            grid[row][col] == '1') {
                            q.push({row, col});
                            grid[row][col] = '0';
                        }
                    }
                }
            }
        }
        return res;
    }
};