#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back
using ll = long long;

const int mod = 1e9 + 7;
const int N = 100005;
ll dp[N][2][2][2];
vector <int> adj[N];

void dfs(int u){
    if (!adj[u].size()){
        dp[u][1][1][1] = 1;
        dp[u][0][0][0] = 1;
        return;
    }
    for (int v : adj[u]) dfs(v);
    for (int j = 0; j < 2; j++){
        int v = adj[u][0];
        dp[u][1][j][0] = dp[v][0][j][0];
        dp[u][1][j][1] = dp[v][0][j][1];
        dp[u][0][j][0] = (dp[v][0][j][0] + dp[v][1][j][0]) % mod;
        dp[u][0][j][1] = (dp[v][0][j][1] + dp[v][1][j][1]) % mod;
        for (int i = 1; i < adj[u].size(); i++){
            v = adj[u][i]; ll t[2];
            t[0] = dp[u][1][j][0];
            t[1] = (dp[u][1][j][1] + t[0]) % mod;
            dp[u][1][j][1] = t[1] * dp[v][0][0][1] + t[0] * dp[v][0][1][1];
            dp[u][1][j][0] = t[1] * dp[v][0][0][0] + t[0] * dp[v][0][1][0];
            t[0] = dp[u][0][j][0];
            t[1] = (t[0] + dp[u][0][j][1]) % mod;
            dp[u][0][j][1] = t[1] * (dp[v][0][0][1] + dp[v][1][0][1]) +
                            t[0] * (dp[v][0][1][1] + dp[v][1][1][1]);
            dp[u][0][j][0] = t[1] * (dp[v][0][0][0] + dp[v][1][0][0]) +
                            t[0] * (dp[v][0][1][0] + dp[v][1][1][0]);
            dp[u][0][j][0] %= mod; dp[u][0][j][1] %= mod;
            dp[u][1][j][0] %= mod; dp[u][1][j][1] %= mod;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 2, j; i <= n; i++){
        cin >> j; adj[j + 1].eb(i);
    }
    dfs(1); ll ans = 0;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                ans = (ans + dp[1][i][j][k]) % mod;
    ans -= (dp[1][0][1][1] + dp[1][1][1][1]) % mod;
    ans = (ans + mod) % mod; cout << ans << '\n';
}