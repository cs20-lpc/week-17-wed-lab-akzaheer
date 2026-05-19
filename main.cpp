// Implement main program.

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
int main() {
    int n = 6;  // 6 nodes
    vector<vector<pair<int,int>>> adj(n);  // adj[u] = {weight, v}
    // edges from the graph
    adj[0].push_back({4, 1});
    adj[0].push_back({9, 2});
    adj[0].push_back({2, 4});
    adj[1].push_back({2, 2});
    adj[1].push_back({1, 3});
    adj[2].push_back({7, 3});
    adj[2].push_back({4, 5});
    adj[3].push_back({1, 5});
    adj[4].push_back({3, 2});
    adj[4].push_back({8, 5});
    for (int src : {0, 1}) {  // run for node 0, then node 1
        vector<int> dist(n, INT_MAX);  // start all distances at infinity
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        dist[src] = 0;
        pq.push(make_pair(0, src));  // push source with cost 0
        while (!pq.empty()) {
            int d = pq.top().first, u = pq.top().second; pq.pop();  // cheapest node
            if (d > dist[u]) continue;  // skip outdated entries
            for (int i = 0; i < adj[u].size(); i++) {
                int w = adj[u][i].first, v = adj[u][i].second;
                if (dist[u] + w < dist[v]) {  // found cheaper path
                    dist[v] = dist[u] + w;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }
        cout << "Shortest distances from node " << src << ":\n";
        for (int i = 0; i < n; i++) {
            cout << "  Node " << i << ": ";
            if (dist[i] == INT_MAX) cout << "INF\n";  // no path
            else cout << dist[i] << "\n";
        }
        cout << "\n";
    }
    return 0;
}