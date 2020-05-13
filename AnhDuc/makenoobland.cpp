#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back
using ll = long long;

const int N = 5e5 + 5;
ll bit[2][N], reqd[N];
int qf[N], qx[N], qd[N], n, m, q, dep[N];
int in[N], out[N], tim, lo[N], hi[N];
vector <int> own[N], ck[N], adj[N];

void dfs(int u, int p){
    in[u] = ++tim;
    for (int v : adj[u])
        if (v != p){
            dep[v] = dep[u] + 1; dfs(v, u);
        }
    out[u] = tim;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 2, j; i <= n; i++){
        cin >> j; adj[j].eb(i);
    }
    for (int i = 1; i <= n; cin >> reqd[i]);
}