#include <bits/stdc++.h>
using namespace std;

using ll = long long;

template <class X, class Y>
bool chkmax(X &a, const Y &b){
    return a < b ? a = b, 1 : 0;
}

const int N = 1e5 + 5;
const int C = 1e6 + 5;
int w[C], cnt[C];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int mx = 0, n; ll res = 0; cin >> n;
    for (int i = 1, x; i <= n; i++){
        cin >> x; cnt[x]++; chkmax(mx, x);
    }
    for (int i = 1; i <= mx; i++){
        w[i] += i; int sum = cnt[i];
        for (int j = 2 * i; j <= mx; j += i){
            w[j] -= w[i]; sum += cnt[j];
        }
        res += 1ll * sum * (sum - 1) * w[i];
    }
    cout << res / 2 << '\n';
}