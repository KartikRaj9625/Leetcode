class Solution {
public:
    bool res = true;
    void dfs(vector<vector<int>>& graph, int node, int c, vector<int>& color) {
        color[node] = c;
        for (int i = 0; i < graph[node].size(); i++) {
            int neigh = graph[node][i];
            if (color[neigh] == c) {
                res = false;
                return;
            }
            if (color[neigh] == -1)
                dfs(graph, neigh, 1 - c, color);
        }
        return;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);

        for (int i = 0; i < V; i++) {
            if (color[i] == -1)
                dfs(graph, i, 0, color);
        }
        return res;
    }
};