#include <bits/stdc++.h>
using namespace std;

double dp[1005];
int w[1005], v[1005], p, l, n;

int main(){
    cin >> n >> p >> l;
    for (int i = 1; i <= n; i++){
        int total = 0, minv = INT_MAX;
        cin >> w[i] >> v[i]; dp[i] = 1e20;
        for (int j = i; j > 0; j--){
            total += w[j]; minv = min(minv, v[j]);
            if (total > p) break;
            dp[i] = min(dp[i], dp[j - 1] + 1.0 * l / minv);
        }
    }
    cout << setprecision(2) << fixed << dp[n] << '\n';
}