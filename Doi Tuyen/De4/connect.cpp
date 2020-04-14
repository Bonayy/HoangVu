#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
vector <int> adj[N];
bitset <N> used;

void dfs(int u){
    used[u] = true;
    for (int v : adj[u])
        if (!used[v]) dfs(v);
}

int main(){
    freopen("connect.inp", "r", stdin);
    freopen("connect.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, u, v, cnt = 0; 
    cin >> n;
    while (cin >> u >> v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        if (!used[i]){
            dfs(i); cnt++;
        }
    cout << cnt << '\n';
}