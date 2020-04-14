#include <bits/stdc++.h>
using namespace std;

vector <int> adj[1005];
int cnt_path = 0, s, t;
bool used[1005];

void dfs(int u){
    used[u] = true;
    if (u == t) cnt_path++;
    for (int v : adj[u])
        if (!used[v]) dfs(v);
    used[u] = false;
}

int main(){
    freopen("findpath.inp", "r", stdin);
    freopen("findpath.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, u, v; cin >> n >> s >> t;
    while (cin >> u >> v){
        adj[u].push_back(v); 
        adj[v].push_back(u);
    }
    dfs(s); cout << cnt_path << '\n';
}