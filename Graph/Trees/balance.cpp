#include <bits/stdc++.h>
using namespace std;

const int N = 2e4 + 5;
int bal[N], siz[N];
bitset <N> avail;
vector <int> g[N];
int n; 
void dfs(int u){
    siz[u] = 1; avail[u] = false;
    for (int v : g[u]) 
        if (avail[v]){
            dfs(v); siz[u] += siz[v];
            bal[u] = max(bal[u], siz[v]);
        }
    bal[u] = max(bal[u], n - siz[u]);
    return;
}

int main(){
    cin >> n; avail.set();
    for (int i = 1, u, v; i < n; i++){
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs(1); 
    int* t = min_element(bal + 1, bal + n + 1);
    cout << t - bal << '\n' << *t;
    return 0;
}