#include <bits/stdc++.h>
using namespace std;

int dp[20][1 << 20], a[20][20];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("tourist.inp", "r", stdin);
    freopen("tourist.out", "w", stdout);
    int n, u, v, w; cin >> n;
    memset(a, 0x3f, sizeof(int) * 20 * 20);
    for (int i = 0; i < n; i++) a[i][i] = 0;
    while (cin >> u >> v >> w){
        a[v][u] = a[--u][--v] = w;
    }
    memset(dp, 0x3f, sizeof(int) * 20 * (1 << 20)); dp[0][1] = 0;
    for (int mask = 1; mask < (1 << n); mask++)
        for (int i = 0; i < n; i++) if (mask & (1 << i))
            for (int j = 0; j < n; j++) if (i != j && (mask & (1 << j)))
                dp[i][mask] = min(dp[i][mask], dp[j][mask ^ (1 << i)] + a[i][j]);
    int res = INT_MAX;
    for (int i = 0; i < n; i++)
        res = min(res, dp[i][(1 << n) - 1] + a[i][0]);
    cout << res << '\n';
}