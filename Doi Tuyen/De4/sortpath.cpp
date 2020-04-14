#include <bits/stdc++.h>
using namespace std;

using ll = long long;
struct edge{
    int v; ll w;
    bool operator < (const edge &o) const {
        return w > o.w;
    }
};

const ll inf = 0x3f3f3f3f3f3f3f3f;
const int N = 100005;
vector <edge> adj[N];
priority_queue <edge> pq;
ll dis[N]; int n;

ll dijkstra(int s, int t){
    priority_queue <edge> ().swap(pq);
    fill_n(dis + 1, n, inf);
    dis[s] = 0; pq.push({s, 0});
    while (!pq.empty()){
        auto c = pq.top(); pq.pop();
        if (c.w != dis[c.v]) continue;
        if (c.v == t) return c.w;
        for (auto e : adj[c.v])
            if (dis[e.v] > dis[c.v] + e.w){
                dis[e.v] = dis[c.v] + e.w;
                pq.push({e.v, dis[e.v]});
            }
    }
    return -1;
}

int main(){
    freopen("sortpath.inp", "r", stdin);
    freopen("sortpath.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int s, t, u, v, w; cin >> n >> s >> t;
    while (cin >> u >> v >> w){
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    cout << dijkstra(s, t) << '\n';
}