#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
vector <int> adj[N];
int child[N];

void dfs(int u, int par){
    child[u] = 1;
    for (int v : adj[u])
        if (v != par){
            dfs(v, u); child[u] += child[v];
        }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    for (int i = 1; i < n; i++){
        int u, v; cin >> u >> v; 
        adj[u].push_back(v); adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++){
        dfs(1, 0); cout << i << ' ';
        cout << accumulate(child + 1, child + n + 1, 0) - n << '\n';
    }
}