#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back
#define all(v) (v).begin(), (v).end()
using ll = long long;

const int N = 1e5 + 5;
int a[N], in[N], out[N], tim; ll dp[N];
vector <int> adj[N], pos[N];

void dfs_init(int u, int p){
    adj[u].erase(find(all(adj[u]), p));
    in[u] = ++tim;
    for (int v : adj[u]) dfs_init(v, u);
    out[u] = tim;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1, u, v; i < n; i++){
        cin >> u >> v;
        adj[u].eb(v); adj[v].eb(u);
    } 
    for (int i = 1; i <= n; cin >> a[i++]);
    
}