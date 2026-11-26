// class Solution {
// public:
//     int minimumEffortPath(vector<vector<int>>& heights) {
//         int n = heights.size();
//         int m = heights[0].size();

//         vector<vector<int>>res(n, vector<int>(m,INT_MAX));
        
//         priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;

//         vector<int> x = {-1,1,0,0};
//         vector<int> y = {0,0,-1,1};

//         res[0][0] = 0;
//         pq.push({0,{0,0}});

//         while(!pq.empty()){

//             auto[dist, pos] = pq.top();
//             pq.pop();
//             int row = pos.first;
//             int col = pos.second;
            
//             // pair<int,pair<int,int>> p = pq.top();
//             // pq.pop();
//             // int dist=p.first;
//             // int row=p.second.first;
//             // int col= p.second.second;

//             if(dist>res[row][col])
//             continue;

//             for(int k = 0;k<x.size();k++){
//                 int r = row+x[k];
//                 int c = col+y[k];
            
//                 if(r<0 || r>=n || c<0 || c>=m)
//                    continue;
            
//                 int abs_diff = abs(heights[row][col]-heights[r][c]);
//                 int new_wt = max(abs_diff,dist);
//                 if(new_wt<res[r][c]){
//                 res[r][c] = new_wt;
//                 pq.push({new_wt,{r,c}}); 
//                 }
//             }  
//         }
//         return res[n-1][m-1];
//     }
// };



class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<int> x = {-1, 1, 0, 0};
        vector<int> y = {0, 0, -1, 1};

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            auto [i, j] = pq.top();
            pq.pop();

            int row = j.first;
            int col = j.second;

            if (i > dist[row][col])
                continue;

            if (row == n - 1 && col == m - 1)
                return i;

            for (int k = 0; k < 4; k++) {
                int row1 = row + x[k];
                int col1 = col + y[k];

                if (row1 >= 0 && row1 < n && col1 >= 0 && col1 < m) {

                    int newEffort =
                        max(i, abs(heights[row1][col1] - heights[row][col]));


                    if (newEffort < dist[row1][col1]) {
                        dist[row1][col1] = newEffort;
                        pq.push({newEffort, {row1, col1}});
                    }
                }
            }
        }

        return 0;
    }
};

