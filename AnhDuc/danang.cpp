/// find shortest from 1 to n such that p_k.w + d <= p_(k + 1).w where p_k is kth edge in the path
/// Solution: Consider every edge as a vertice in a new graph G'
#include <bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(), (v).end()
#define lb lower_bound
#define ub upper_bound
using ll = long long;
struct edge{
    int from, to, nxt; ll w;
};

struct path{
    edge *e; ll w;
    bool operator < (const path &o) const {
        return w > o.w;
    }
};

const int N = 2e5 + 5;
edge lst[N << 1]; ll dis[N << 1];
vector <int> adj[N];
priority_queue <path> pq;

int main(){
    freopen("danang.inp", "r", stdin);
    freopen("danang.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m, d; cin >> n >> m >> d;
    for (int i = 1; i <= m; i++){
        int u, v; ll w; cin >> u >> v >> w;
        lst[i] = {u, v, 0, w};
        lst[i + m] = {v, u, 0, w};
        adj[u].push_back(i);
        adj[v].push_back(i + m);
    }
    if (adj[1].empty()) return cout << "-1\n", 0;
    auto cmp = [](const int &x, const int &y){
        return lst[x].w < lst[y].w;
    };
    for (int u = 1; u <= n; u++){
        sort(all(adj[u]), cmp);
        for (int i = 0; i < size(adj[u]) - 1; i++)
            lst[adj[u][i]].nxt = adj[u][i + 1];
    }
    memset(dis, 0x3f, sizeof dis);
    pq.push({lst + adj[1][0], lst[adj[1][0]].w});
    dis[adj[1][0]] = lst[adj[1][0]].w;
    while (!pq.empty()){
        auto cur = pq.top(); pq.pop();
        if (dis[cur.e - lst] < cur.w) continue;
        if (cur.e->to == n){
            cout << cur.w << '\n'; return 0;
        }
        if (cur.e->nxt){
            auto nxt = cur.e->nxt;
            if (dis[nxt] > cur.w - cur.e->w + lst[nxt].w){
                dis[nxt] = cur.w - cur.e->w + lst[nxt].w;
                pq.push({lst + nxt, dis[nxt]});
            }
        }
        lst[0].w = cur.e->w + d;
        auto it = lb(all(adj[cur.e->to]), 0, cmp);
        if (it != adj[cur.e->to].end()){
            if (dis[*it] > cur.w + lst[*it].w){
                dis[*it] = cur.w + lst[*it].w;
                pq.push({lst + *it, dis[*it]});
            }
        }
    }
    cout << "-1\n"; return 0;
}