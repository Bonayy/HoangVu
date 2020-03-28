#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
vector <int> adj[N];
int dep[N];

void dfs(int u, int p){
    for (int v : adj[u])
        if (v != p){
            dep[v] = dep[u] + 1; dfs(v, u);
        }
}

int main(){
    int n; cin >> n;
    for (int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(8, 0);
    cout << accumulate(dep + 1, dep + n + 1, 0) << '\n';
}