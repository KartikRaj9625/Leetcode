class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> res(n, 1e8);
        res[src] = 0;
        for (int i = 0; i <= k; i++) {
            vector<int> temp = res;
            for (auto edge : flights) {
                int src = edge[0];
                int dst = edge[1];
                int wt =  edge[2];

                if (res[src] != 1e8 && temp[dst] > res[src] + wt) {
                    temp[dst] = res[src] + wt;
                }
            }
            res = temp;
        }
        if (res[dst] == 1e8)
            return -1;
        return res[dst];
    }
};