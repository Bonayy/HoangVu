#include <bits/stdc++.h>
using namespace std;

template <class X, class Y>
bool chkmax(X &a, const Y &b) {
    return a < b ? a = b, 1 : 0;
}

using ll = long long;

const int N = 1e5 + 5;
ll n[3], sz[3][N], ver[N][2], h[3][N];
ll cur, sd[3][N], dp[N][2], mx[3], res;
vector <int> adj[3][N];

void dfs(int id, int u, int p) {
    sz[id][u] = 1;
    for (int v : adj[id][u]) {
        if (v == p) continue;
        h[id][v] = h[id][u] + 1;
        dfs(id, v, u);
        sz[id][u] += sz[id][v];
        cur += sz[id][v];
    }
}

void go(int id, int u, int p) {
    int last = sz[id][u];
    if (p) {
        sz[id][u] = n[id];
        sz[id][p] = n[id] - last;
        cur += n[id] - 2 * last;
    }
    sd[id][u] = cur;
    chkmax(mx[id], cur);
    for (int v : adj[id][u]) {
        if (v == p) continue;
        go(id, v, u);
    }
    if (p) {
        sz[id][p] = n[id];
        sz[id][u] = last;
        cur -= n[id] - 2 * last;
    }
}

void cal(int id, int u, int p) {
    for (int v : adj[id][u]) {
        if (v == p) continue;
        cal(id, v, u);
    }
    int pid = (id + 2) % 3;
    int sid = (id + 1) % 3;
    ver[u][0] = ver[u][1] = u;
    dp[u][0] = sd[id][u] * n[pid] +
    n[pid] * n[sid] * h[u];
    dp[u][1] = sd[id][u] * n[sid] +
    n[pid] * n[sid] * h[u];
    for (int v : adj[id][u]) {
        if (v == p) continue;
        chkmax(res, n[id] * n[pid] +
        n[id] * n[sid] + n[pid] * n[sid] * 2
        mx[pid] * n[id] + mx[pid] * n[sid] +
        mx[sid] * n[id] + mx[sid] * n[pid]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n[0] >> n[1] >> n[2];
    for (int id = 0; id < 3; id++) {
        for (int i = 1; i < n[id]; i++) {
            int u, v; cin >> u >> v;
            adj[id][u].push_back(v);
            adj[id][v].push_back(u);
        }
    }
    for (int id = 0; id < 3; id++) {
        cur = 0;
        dfs(id, 1, 0); go(id, 1, 0);
    }
}
