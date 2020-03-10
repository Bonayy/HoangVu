
#include <bits/stdc++.h>
using namespace std;

#define popcnt(x) __builtin_popcountll(x)
#define clz(x) __builtin_clzll(x)
#define ctz(x) __builtin_ctzll(x)
#define FOR(i, j, k) for (int i = (j); i < (k); i++)
#define FORD(i, j, k) for (int i = (j); i >= (k); i--)

int a[12][12];
int dp[12][1 << 12];
const int inf = 0x3f3f3f3f;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin >> n >> m;
    for (int i = 0, u, v, w; i < m; i++){
        cin >> u >> v >> w;
        u--; v--;
        if (a[u][v] > 0) w = min(w, a[u][v]);
        a[u][v] = a[v][u] = w;
    }
    memset(dp, 0x3f, sizeof dp);
    FOR(i, 0, n) dp[i][1 << i] = 0;
    int state = 1 << n;
    FOR(mask, 0, state) FOR(i, 0, n) if (mask & (1 << i)) FOR(j, 0, n)
        if (j != i && mask & (1 << j) && a[i][j] > 0){
            dp[i][mask] = min(dp[i][mask], dp[j][mask ^ (1 << i)] + a[i][j]);
        }
    int ans = inf;
    FOR(i, 0, n) ans = min(ans, dp[i][state - 1]);
    cout << ans;
}
