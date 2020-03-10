
#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

using ii = pair <int, int>;
const int N = 1e5 + 5;
vector <int> adj[N];
int anc[N], ans[N], par[N];
int n, root, rnk[N];
bitset <N> used;
vector <ii> que[N];

int find_set(int u){
    if (u != par[u]) 
        par[u] = find_set(par[u]);
    return par[u];
}

bool union_set(int u, int v){
    u = find_set(u);
    v = find_set(v);
    if (u == v) return false;
    if (rnk[u] == rnk[v]) rnk[u]++;
    if (rnk[u] > rnk[v]) par[v] = u;
    else par[u] = v;
    return true;
}

void dfs(int u){
    used[u] = true; anc[u] = u;
    par[u] = u; rnk[u] = 0;
    for (int v : adj[u])
        if (!used[v]){
            dfs(v); union_set(u, v);
            anc[find_set(v)] = u;
        }
    for (auto qq : que[u]){
        if (used[qq.fi])
            ans[qq.se] = anc[find_set(qq.fi)];
    }
}

void solve(){
    cin >> n; int q, u, v;
    for (int i = 1; i <= n; i++){
        adj[i].clear(); 
        used[i] = false;
    }
    for (int i = 1; i <= n; i++){
        int m, c; cin >> m;
        while (m--){
            cin >> c; par[c] = i;
            adj[i].push_back(c);
        }
    }
    for (int i = 1; i <= n; i++)
        if (par[i] == 0) root = i;
    cin >> q;
    for (int i = 1; i <= q; i++){
        cin >> u >> v;
        que[u].push_back({v, i});
        que[v].push_back({u, i});
    }
    dfs(root);
    for (int i = 1; i <= q; i++)
        cout << ans[i] << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    for (int i = 1; i <= t; i++){
        cout << "Case " << i << ":\n";
        solve();
    }
}