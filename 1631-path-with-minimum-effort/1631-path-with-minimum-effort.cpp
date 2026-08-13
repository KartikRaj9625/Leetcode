class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>>res(n, vector<int>(m,INT_MAX));
        
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;

        vector<int> x = {-1,1,0,0};
        vector<int> y = {0,0,-1,1};

        res[0][0] = 0;
        pq.push({0,{0,0}});

        while(!pq.empty()){

            auto[dist, pos] = pq.top();
            pq.pop();
            int row = pos.first;
            int col = pos.second;
            
            // pair<int,pair<int,int>> p = pq.top();
            // pq.pop();
            // int dist=p.first;
            // int row=p.second.first;
            // int col= p.second.second;

            if(dist>res[row][col])
            continue;

            for(int k = 0;k<x.size();k++){
                int r = row+x[k];
                int c = col+y[k];
            
                if(r<0 || r>=n || c<0 || c>=m)
                   continue;
            
                int abs_diff = abs(heights[row][col]-heights[r][c]);
                int new_wt = max(abs_diff,dist);
                if(new_wt<res[r][c]){
                res[r][c] = new_wt;
                pq.push({new_wt,{r,c}}); 
                }
            }  
        }
        return res[n-1][m-1];
    }
};