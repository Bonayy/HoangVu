#include <bits/stdc++.h>
using namespace std;

int a[1005][1005], dp[1005][1005];
const int inf = 0x3f3f3f3f;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("messages.inp", "r", stdin);
    freopen("messages.out", "w", stdout);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++){
            cin >> a[i][j]; 
            dp[i][j] = a[i][j];
        }
    for (int i = 1; i <= n; i++)
        dp[i][0] = inf;
    for (int j = 1; j <= m; j++)
        for (int i = 1; i <= n; i++)
            for (int k = 0; k <= i; k++)
                dp[i][j] = min(dp[i][j], dp[i - k][j - 1] + a[k][j]);
    cout << dp[n][m] << '\n'; vector <int> ans; int tmp = m;
    while (n > 0 && m > 0){
        for (int k = 0; k <= n; k++)
            if (dp[n][m] == dp[n - k][m - 1] + a[k][m]){
                ans.push_back(k); n -= k; m--; break;
            }
    }
    while (ans.size() < tmp) ans.push_back(0);
    for (auto it = ans.rbegin(); it != ans.rend(); it++)
        cout << *it << '\n';
}