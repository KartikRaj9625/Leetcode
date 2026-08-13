class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> res(n, vector<int>(m, 1e8));

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        vector<int> x = {-1, 1, 0, 0};
        vector<int> y = {0, 0, -1, 1};

        res[0][0] = grid[0][0];
        pq.push({grid[0][0], {0, 0}});

        while (!pq.empty()) {
            auto [money, pos] = pq.top();
            pq.pop();
            int row = pos.first;
            int col = pos.second;

            if (money > res[row][col])
                continue;

            for (int k = 0; k < x.size(); k++) {
                int r = row + x[k];
                int c = col + y[k];

                if (r < 0 || r >= n || c < 0 || c >= m)
                    continue;

                int new_money = max(money, grid[r][c]);

                if (new_money < res[r][c]) {
                    res[r][c] = new_money;
                    pq.push({new_money, {r, c}});
                }
            }
        }
        return res[n - 1][m - 1];
    }
};