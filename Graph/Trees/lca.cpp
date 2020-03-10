#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cout << #x << " = " << x << '\n'

const int N = 1e5 + 5;
int n, dep[N], anc[N][20], root;
 
int calc_dep(int u){
    if (u == root) return dep[u] = 1;
    if (dep[u] == 0) 
        dep[u] = calc_dep(anc[u][0]) + 1;
    return dep[u];
}
 
int lca(int u, int v){
    for (int k = 19; k >= 0; k--)
        if (dep[anc[u][k]] >= dep[v])
            u = anc[u][k];
    for (int k = 19; k >= 0; k--)
        if (dep[anc[v][k]] >= dep[u])
            v = anc[v][k];
    if (u == v) return u;   
    for (int k = 19; k >= 0; k--)
        if (anc[u][k] != anc[v][k]){
            u = anc[u][k]; v = anc[v][k];
        }
    return anc[u][0];
}
 
void solve(){
    cin >> n; int u, v;
    for (int i = 1; i <= n; i++){
        int m, c; cin >> m;
        while (m--){
            cin >> c; anc[c][0] = i;
        }
    }
    for (int i = 1; i <= n; i++)
        if (anc[i][0] == 0) root = i;
    for (int i = 1; i <= n; i++) calc_dep(i);
    for (int k = 1; k <= 19; k++)
        for (int i = 1; i <= n; i++)
            anc[i][k] = anc[anc[i][k - 1]][k - 1];
    int q; cin >> q;
    while (q--){
        cin >> u >> v; cout << lca(u, v) << '\n';
    }
    
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