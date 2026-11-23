class Solution {
public:
bool valid(int row,int col,int n,int m){
    if(row<0 || row>=n || col<0 || col>=m){
        return false;
    }else{return true;}
}
queue<pair<int,int>>q;
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int time = 0;
        int fresh = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        vector<int>x = {-1,1,0,0};
        vector<int>y = {0,0,-1,1};
        while(!q.empty() && fresh>0){
            time++;
            int size = q.size();
            while(size--){
                auto[i,j] = q.front();
                // pair<int,int>p = q.front();
                // int i = p.first;
                // int j = p.second;

                q.pop();
                for(int k = 0; k<x.size();k++){
                    int row = i + x[k];
                    int col = j + y[k];

                    if(valid(row,col,n ,m) && grid[row][col] == 1){
                        q.push({row,col});
                        grid[row][col] = 2;
                        fresh--;
                    }
                }
            }
        }
        if(fresh>0)
        return -1;
        return time;
    }
};