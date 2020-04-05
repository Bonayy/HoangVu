#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int mod = 1e9 + 7;
int dp[N], sum[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m, k; cin >> n >> m >> k;
    fill_n(dp + 1, n, -1);
    dp[0] = sum[0] = 1;
    while (k--){
        int x; cin >> x; dp[x] = 0;
    }
    for (int i = 1; i <= n; i++){
        if (dp[i] == 0){
            sum[i] = sum[i - 1]; continue;
        }
        if (i > m)
            dp[i] = (sum[i - 1] - sum[i - m - 1] + mod) % mod;
        else dp[i] = sum[i - 1];
        sum[i] = (sum[i - 1] + dp[i]) % mod;
    }
    cout << dp[n] << '\n'; return 0;
}