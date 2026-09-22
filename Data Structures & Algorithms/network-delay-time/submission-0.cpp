class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int m = times.size();
        unordered_map<int, vector<pair<int, int>>> adj;
        vector<int> dist(n+1, 1e9);

        for(int i = 0; i < m ; i++){
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            adj[u].push_back({v, w});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        dist[k] = 0;

        while(!pq.empty()){
            auto [d, node] = pq.top();
            pq.pop();

            if(d > dist[node]) continue;

            for(auto& [neigh, w] : adj[node]){
                if(d + w < dist[neigh]){
                    dist[neigh] = d + w;
                    pq.push({dist[neigh], neigh});
                }
            }
        }

        int ti = 0;
        for(int i = 1; i <= n; i++){
            ti = max(ti, dist[i]);
        }

        return (ti == 1e9) ? -1 : ti;
    }
};
