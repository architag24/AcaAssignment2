#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int64_t> dijkstra(int V, vector<vector<pair<int, int64_t>>> &adj, int S) {
        priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>, greater<pair<int64_t, int>>> pq;
        vector<int64_t> distTo(V, numeric_limits<int64_t>::max());
        
        distTo[S] = 0;
        pq.push({0, S});
        
        while (!pq.empty()) {
            int node = pq.top().second;
            int64_t dis = pq.top().first;
            pq.pop();
            
            if (dis > distTo[node]) continue;

            for (auto &it : adj[node]) {
                int v = it.first;
                int64_t w = it.second;
                
                if (dis + w < distTo[v]) {
                    distTo[v] = dis + w;
                    pq.push({dis + w, v});
                }
            }
        }
        return distTo;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    
    vector<vector<pair<int, int64_t>>> adj(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        int64_t c;
        cin >> a >> b >> c;
        adj[a - 1].push_back({b - 1, c});
    }
    
    Solution obj;
    vector<int64_t> res = obj.dijkstra(n, adj, 0);
    
    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    
    return 0;
}