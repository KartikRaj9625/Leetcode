class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;

        int fresh = 0;

        // Find all rotten oranges and count fresh oranges
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 2) {
                    q.push({i, j});
                }

                else if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int minutes = 0;

        vector<int> x= {-1, 1, 0, 0};
        vector<int> y = {0, 0, -1, 1};

        while(!q.empty() && fresh > 0) {

            int size = q.size();

            // One complete level = one minute
            while(size--) {

                auto [i, j] = q.front();
                q.pop();

                for(int k = 0; k < x.size(); k++) {

                    int row = i + x[k];
                    int col = j + y[k];

                    if(row >= 0 && row < n &&
                       col >= 0 && col < m &&
                       grid[row][col] == 1) {

                        grid[row][col] = 2;
                        fresh--;
                        q.push({row, col});
                    }
                }
            }

            minutes++;
        }

        // Fresh oranges still remaining
        if(fresh > 0)
            return -1;

        return minutes;
    }
};