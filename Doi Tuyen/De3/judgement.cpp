#include <bits/stdc++.h>
using namespace std;

struct edge{
    int u, w;
    bool operator < (const edge &o) const {
        return w < o.w;
    }
};

const int N = 1005;
vector <edge> adj[N];
int dis[N], n, m;

int dijkstra(int s, int t){
    priority_queue <edge> pq; 
    dis[s] = INT_MAX; pq.push({s, dis[s]});
    while (!pq.empty()){
        auto cur = pq.top(); pq.pop();
        if (cur.w < dis[cur.u]) continue;
        if (cur.u == t) return cur.w;
        for (auto e : adj[cur.u])
            if (dis[e.u] < min(cur.w, e.w)){
                dis[e.u] = min(cur.w, e.w);
                pq.push({e.u, dis[e.u]});
            }
    }
    return -1;
}

int main(){
    int s, t, u, v, w; cin >> n >> m >> s >> t;
    while (cin >> u >> v >> w){
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    cout << (m - 1) / min(dijkstra(s, t), 50) + 1;
}