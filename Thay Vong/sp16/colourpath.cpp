#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back
#define all(v) (v).begin(), (v).end()
using ll = long long;

const int N = 1e5 + 5;
int a[N], sz[N], n, s[N];
vector <int> adj[N]; ll res[N];

void dfs_sz(int u, int p){
    sz[u] = 1;
    for (int v : adj[u]){
        if (v == p) continue;
        dfs_sz(v, u);
        sz[u] += sz[v];
    }
}

void dfs_sol(int u, int p){
    ll tmp = n - sz[u] - s[a[u]] + 1;
    for (int v : adj[u]){
        if (v == p) continue;
        s[a[u]] += n - sz[v];
        dfs_sol(v, u);
        s[a[u]] -= n - sz[v];
        tmp *= (sz[v] + 1);
    }
    s[a[u]] += sz[u];
    res[a[u]] += tmp;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cin >> n;
    for (int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        adj[u].eb(v); adj[v].eb(u);
    } 
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    dfs_sz(1, 0); dfs_sol(1, 0);
    for (int i = 1; i <= n; i++)
        cout << res[i] << '\n';
}