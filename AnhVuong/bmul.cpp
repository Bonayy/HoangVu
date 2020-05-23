#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
using ll = long long;
int f[500005][2][2], g[500005][2][2], a[51];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    f[0][1][0] = 1; int n = 0;
    ll m, u, b; cin >> m >> u >> b;
    if (m <= 500000){
        while (u > 0){
            a[++n] = u % b; u /= b;
        }
        reverse(a + 1, a + n + 1);
        for (int i = 1; i <= n; ++i){
            for (int j = 0; j < m; ++j)
                for (int l = 0; l <= 1; ++l)
                    for (int k = 0; k <= 1; ++k){
                        int lim = l ? a[i] : b - 1;
                        for (int dgt = k; dgt <= lim; ++dgt){
                            int _j = (j * b + dgt) % m;
                            int _l = l && dgt == a[i];
                            int _k = dgt > 0;
                            g[_j][_l][_k] = (g[_j][_l][_k] +
                                            f[j][l][k]) % mod;
                        }
                    }
            swap(f, g);
            for (int j = 0; j < m; ++j)
                g[j][0][0] = g[j][0][1] = 0,
                g[j][1][0] = g[j][1][1] = 0;
        }
        cout << (f[0][0][1] + f[0][1][1]) % mod << '\n';
    }
    else {
        int res = u / m;
        for (int i = 1; m * i <= u; ++i){
            ll x = m * i;
            while (x > 0){
                if (x % b == 0){res--; break;} x /= b;
            }
        }
        cout << res << '\n';
    }
}