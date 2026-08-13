class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i = 0; i<times.size();i++){
            int src = times[i][0];
            int dst = times[i][1];
            int time = times[i][2];
            adj[src-1].push_back({dst-1,time});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        vector<int> shorttime(n,INT_MAX);

        shorttime[k-1]=0;
        pq.push({k-1,0});

        while(!pq.empty()){
            auto[node, time] = pq.top();
            pq.pop();

            if(time>shorttime[node])
            continue;

            for(int i=0; i<adj[node].size();i++){
                int neigh = adj[node][i].first;
                int t = adj[node][i].second;

                if(time + t < shorttime[neigh]){
                    shorttime[neigh]= time + t;
                    pq.push({neigh, time + t});
                }
            }
        }
        int max_val = *max_element(shorttime.begin(), shorttime.end());
        if(max_val==INT_MAX)
          return -1;
        return max_val;  
        
    }
};