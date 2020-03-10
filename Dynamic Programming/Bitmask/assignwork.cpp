#include <bits/stdc++.h>
using namespace std;
#define popcnt(x) __builtin_popcountll(x)
#define clz(x) __builtin_clzll(x)
#define ctz(x) __builtin_ctzll(x)
#define FOR(i, j, k) for (int i = (j); i < (k); i++)
#define FORD(i, j, k) for (int i = (j); i >= (k); i--)

int dp[1 << 20];
int cost[22][22];
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); ll state;
    int n; cin >> n; state = 1 << n;
    FOR(i, 0, n) FOR(j, 0, n) cin >> cost[i][j];
    memset(dp, 0x3f, sizeof dp); dp[0] = 0;
    FOR(mask, 0, state){
        int i = popcnt(mask);
        FOR(j, 0, n)
            dp[mask | (1 << j)] = min(dp[mask | (1 << j)], dp[mask] + cost[i][j]);
    }
    cout << dp[state - 1];
}
