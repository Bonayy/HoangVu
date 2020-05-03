#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 8005;
const int K = 805;
const ll inf = 0x3f3f3f3f3f3f3f3f;

ll f[N], g[N], sum[N];

ll cost(int i, int j){
    if (i > j) return 0;
    return (sum[j] - sum[i - 1]) * (j - i + 1);
}

void solve(int l, int r, int optl, int optr){
    int optm, m = (l + r) >> 1;
    for (int i = optl; i <= optr; i++)
        if (g[m] > f[i] + cost(i + 1, m))
            g[m] = f[optm = i] + cost(i + 1, m);
    if (l < m) solve(l, m - 1, optl, optm);
    if (m < r) solve(m + 1, r, optm, optr);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> sum[i];
        sum[i] += sum[i - 1]; f[i] = sum[i] * i;
    }
    while (--k){
        fill_n(g + 1, n, inf);
        solve(1, n, 1, n); swap(f, g);
    }
    cout << f[n] << '\n';
}