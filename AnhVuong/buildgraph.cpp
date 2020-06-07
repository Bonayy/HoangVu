#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back

const int N = 2e5 + 5;
vector <int> adj[2][N], g[N];
vector <int> ext, cmp, topo;
int par[N]; bitset <N> used, ok;

void dfs(int u, bool rev){
    used[u] = true;
    if (rev) cmp.eb(u);
    for (int v : adj[rev][u])
        if (!used[v]) dfs(v, rev);
    if (!rev) ext.eb(u);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m, res = 0; cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;
        adj[0][u].eb(v);
        adj[1][v].eb(u);
    }
    for (int u = 1; u <= n; u++)
        if (!used[u]) dfs(u, 0);
    used.reset();
    reverse(ext.begin(), ext.end());
    for (int u : ext) if (!used[u]){
        cmp.clear(); dfs(u, 1);
        if (cmp.size() > 1)
            res += cmp.size();
        for (int v : cmp) par[v] = u;
        topo.eb(u);
    }
    for (int u = 1; u <= n; u++)
        for (int v : adj[0][u])
            if (par[v] != par[u])
                g[par[u]].eb(par[v]);
    reverse(topo.begin(), topo.end());
    for (int u : topo){
        for (int v : g[u])
            if (!ok[v]){
                ok[v] = 1; res++;
            }
    }
    cout << res << '\n';
}