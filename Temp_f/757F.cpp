#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back
using ll = long long;

struct edge{
    int v; ll w;

    bool operator <
    (const edge &o) const {
        return w > o.w;
    }

    edge(){}

    edge(int v, ll w): v(v), w(w){}
};

const int N = 2e5 + 5;
int root[N], cnt[N]; ll dis[N];
priority_queue <edge> pq;
vector <edge> adj[N];

void dijkstra(int s){
    memset(dis, 0x3f, sizeof dis);
    dis[s] = 0;
    for (auto e : adj[s]){
        dis[e.v] = e.w; pq.push(e);
        root[e.v] = e.v;
    }
    while (!pq.empty()){
        auto cur = pq.top(); pq.pop();
        if (cur.w != dis[cur.v]) continue;
        for (edge e : adj[cur.v])
            if (dis[e.v] > cur.w + e.w){
                dis[e.v] = cur.w + e.w;
                root[e.v] = root[cur.v];
            }
            else if (dis[e.v] == cur.w + e.w){
                if (root[e.v] != root[cur.v])
                    root[e.v] = e.v;
            }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m, s; cin >> n >> m >> s;
    while (m--){
        int u, v; ll w; cin >> u >> v >> w;
        adj[u].eb(v, w); adj[v].eb(u, w);
    }
    dijkstra(s); int mx = 0;
    for (int i = 1; i <= n; i++)
        if (root[i])
            mx = max(mx, ++cnt[root[i]]);
    cout << mx << '\n';
}