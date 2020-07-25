#include <bits/stdc++.h>
using namespace std;

template <class X, class Y>
bool chkmax(X &a, const Y &b) {
    return a < b ? a = b, 1 : 0;
}

using ll = long long;

const int N = 1e5 + 5;
ll n[3], sz[3][N], h[3][N], res;
ll sd[3][N], dp[N][2], mx[3];
vector <int> adj[3][N]; ll tmp;

void dfs(int id, int u, int p) {
    sz[id][u] = 1;
    for (int v : adj[id][u]) {
        if (v == p) continue;
        h[id][v] = h[id][u] + 1;
        dfs(id, v, u);
        sz[id][u] += sz[id][v];
        sd[id][1] += sz[id][v];
    }
}

void go(int id, int u, int p) {
    if (p) {
        sd[id][u] = sd[id][p];
        sd[id][u] +=
        n[id] - 2 * sz[id][u];
    }
    tmp += sd[id][u];
    chkmax(mx[id], sd[id][u]);
    for (int v : adj[id][u]) {
        if (v == p) continue;
        go(id, v, u);
    }
}

void cal(int id, int u, int p) {
    for (int v : adj[id][u]) {
        if (v == p) continue;
        cal(id, v, u);
    }
    int pid = (id + 2) % 3;
    int sid = (id + 1) % 3;
    dp[u][0] = sd[id][u] * n[pid] +
    n[pid] * n[sid] * h[id][u];
    dp[u][1] = sd[id][u] * n[sid] +
    n[pid] * n[sid] * h[id][u];
    ll sub = h[id][u] * n[pid] * n[sid];
    ll add = n[id] * n[pid] +
    n[id] * n[sid] + n[pid] * n[sid] * 2
    + mx[pid] * n[id] + mx[pid] * n[sid]
    + mx[sid] * n[id] + mx[sid] * n[pid];
    for (int v : adj[id][u]) {
        if (v == p) continue;
        chkmax(res, add - sub * 2
        + max(dp[u][0] + dp[v][1],
        dp[u][1] + dp[v][0]));
        chkmax(dp[u][0], dp[v][0]);
        chkmax(dp[u][1], dp[v][1]);
    }
    chkmax(res, add - sub * 2 +
    sd[id][u] * (n[pid] + n[sid]));
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
        dfs(id, 1, 0); go(id, 1, 0);
    }
    for (int id = 0; id < 3; id++) {
        cal(id, 1, 0);
    }
    cout << res + tmp / 2 << '\n';
}
