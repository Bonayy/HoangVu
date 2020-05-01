#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct edge{
    int from, to; ll w;
};

struct path{
    int u, id; ll w;

    bool operator < (const path &o){
        return w > o.w;
    }
};

const int N = 2e5 + 5;
ll dis[2 * N]; edge edges[2 * N];
vector <int> adj[N];
priority_queue <path> pq;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m; ll d; cin >> n >> m >> d;
    for (int i = 1; i <= m; i++){
        int u, v; ll w; cin >> u >> v >> w;
        edges[i] = {u, v, w};
        edges[i + m] = {v, u, w};
        adj[u].push_back(i);
        adj[v].push_back(i + m);
    }
    for (int i = 1; i <= n; i++)
        sort(adj[i].begin(), adj[i].end(),
        [](const int &x, const int &y){
            return edges[x].w < edges[y].w;
        });
    pq.push({1, 0, edges[adj[1][0]].w});
    while (!pq.empty()){
        auto cur = pq.top(); pq.pop();
        
    }
}