// class Solution {
// public:
//     bool valid(int i, int j, int n, int m) {
//         if (i < 0 || i >= n || j < 0 || j >= m)
//             return false;
//         return true;
//     }

//     vector<int> x = {-1, 1, 0, 0};
//     vector<int> y = {0, 0, -1, 1};

//     void dfs(vector<vector<char>>& grid, int n, int m, int i, int j,vector<vector<bool>>& visited) {

//         visited[i][j] = 1;

//         for (int k = 0; k < x.size(); k++) {
//             int row = i + x[k];
//             int col = j + y[k];

//             if (valid(row, col, n, m) && grid[row][col] == '1' &&
//                 visited[row][col] == 0) {
//                 dfs(grid, n, m, row, col, visited);
//             }
//         }
//     }
//     int numIslands(vector<vector<char>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//         int res = 0;
//         int i, j;
//         vector<vector<bool>> visited(n, vector<bool>(m, 0));

//         // for (i = 0; i < n; i++) {
//         //     vector<bool> t(m, 0);
//         //     visited[i] = t;
//         // }
//         for (i = 0; i < n; i++) {
//             for (j = 0; j < m; j++) {
//                 if (grid[i][j] == '1' && visited[i][j] == 0) {
//                     dfs(grid, n, m, i, j, visited);
//                     res++;
//                 }
//             }
//         }
//         return res;
//     }
// };

class Solution {
public:

    vector<int>x= {-1, 1, 0, 0};
    vector<int>y= {0, 0, -1, 1};

    void dfs(vector<vector<char>>& grid, int i, int j) {

        int n = grid.size();
        int m = grid[0].size();

        // check for outside + water
        if(i < 0 || i >= n || j < 0 || j >= m ||
           grid[i][j] == '0')
            return;

        // Mark visited
        grid[i][j] = '0';

        // 4 directions
        for(int k = 0; k < x.size(); k++) {

            dfs(grid, i + x[k], j + y[k]);//visited now check neigh
        }
    }

    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int res = 0;

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {

                if(grid[i][j] == '1') {
                    res++;//land 
                    dfs(grid, i, j); //jump on it
                }
            }
        }

        return res;
    }
};