#include <bits/stdc++.h>
using namespace std;

typedef vector <int> vi;
const int maxn = 1e5 + 10;
vi adj[maxn]; int par[maxn];
int source, sink, tmp;
int maxp; int res[maxn];
bool avail[maxn];
void dfs(int u, int d = 0){
    avail[u] = 0;
    if (d > maxp){
        maxp = d;
        res[u] = par[u];
        sink = u;
    }
    for (auto v : adj[u])
        if (avail[v]){
            par[v] = u; dfs(v, d + 1);
        }
}

void maxpath(){
    memset(avail, 1, sizeof avail);
    dfs(1); source = sink; maxp = 0;
    memset(avail, 1, sizeof avail);
    memset(par, 0, sizeof par);
    dfs(source);
    cout << maxp << '\n';
    while (sink != 0){
        cout << sink << ' ';
        sink = par[sink];
    }
}

int main(){
    int n, u, v; cin >> n;
    while (--n){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    maxpath(); return 0;
}
