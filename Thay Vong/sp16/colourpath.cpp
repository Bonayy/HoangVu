#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back
#define pb pop_back
using ll = long long;

const int N = 1e5 + 5;
vector <int> st[N], adj[N];
int n, s[N], c[N], tim;
int in[N], out[N], sz[N];
ll ans[N];

bool is_anc(int u, int v){
    return in[u] >= in[v] &&
            out[u] <= out[v];
}

void dfs_sz(int u, int p){
    sz[u] = 1; in[u] = ++tim;
    for (int v : adj[u]){
        if (v == p) continue;
        dfs_sz(v, u);
        sz[u] += sz[v];
    }
    out[u] = tim;
}

void dfs_sol(int u, int p){
    ll tmp = n - sz[u] - s[c[u]] + 1;
    ans[c[u]] += tmp;
    int last = s[c[u]]; s[c[u]] = 0;
    for (int v : adj[u]){
        if (v == p) continue;
        ans[c[u]] += tmp * sz[v];
        tmp += sz[v];
        s[c[u]] += n - sz[v];
        dfs_sol(v, u);
        s[c[u]] -= n - sz[v];
    }
    s[c[u]] += sz[u] + last;
    while (is_anc(st[c[u]].back(), u)){
        s[c[u]] -= sz[st[c[u]].back()];
        st[c[u]].pop_back();
    }
    st[c[u]].eb(u);
}

int main(){
    freopen("colourpath.inp", "r", stdin);
    freopen("colourpath.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cin >> n;
    for (int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        adj[u].eb(v); adj[v].eb(u);
    }
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= n; i++) st[i].eb(0);
    dfs_sz(1, 0); dfs_sol(1, 0);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << '\n';
}