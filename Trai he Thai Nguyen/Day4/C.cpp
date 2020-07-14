#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e6 + 5;
const int mod = 10000007;
int lp[N], lo[4 * N], hi[4 * N];
int pr[N], que[N], num;
ll f[N], cn[N]; bitset <N> has;

void sieve(){
    for (int i = 2; i < N; i++){
        if (lp[i] == 0){
            lp[i] = i; pr[++num] = i;
        }
        for (int j = 1; j <= num &&
        pr[j] <= lp[i] && i * pr[j] < N; j++)
            lp[i * pr[j]] = pr[j];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); sieve();
    int q, mx = 0; cin >> q;
    for (int i = 1; i <= q; i++){
        cin >> que[i]; has[que[i]] = 1;
        mx = max(mx, que[i]);
    }
    f[1] = 1;
    for (int i = 2; i <= mx; i++){
        int x = i;
        while (x > 1){
            cn[lp[x]]++; x /= lp[x];
        }
        if (has[i]){
            ll res = 1;
            for (int j = 1; j <= num; j++)
                res = (cn[pr[j]] + 1) *
                (cn[pr[j]] + 2) / 2 %
                mod * res % mod;
            f[i] = res;
        }
    }
    for (int i = 1; i <= q; i++)
        cout << f[que[i]] << '\n';
}