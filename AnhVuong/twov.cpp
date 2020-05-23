#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int dep[N], anc[19][N];
vector <int> adj[N], que[N];

void dfs(int u, int p){
    for (int v : adj[u])
        if (v != p){
            dep[v] = dep[u] + 1;
            dfs(v, u); anc[0][v] = u;
        }
}

int lca(int u, int v){
    if (dep[u] < dep[v]) return lca(v, u);
    for (int k = 18; ~k; k--)
        if (dep[anc[k][u]] >= dep[v])
            u = anc[k][u];
    if (u == v) return u;
    for (int k = 18; ~k; k--)
        if (anc[k][u] != anc[k][v]){
            u = anc[k][u]; v = anc[k][v];
        }
    return anc[0][u];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
}