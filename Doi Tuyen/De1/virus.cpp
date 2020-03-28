#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int a[N], bit[N], n;

void update(int i){
    for (; i <= n; i += i & -i) bit[i]++;
}

int retrieve(int i){
    int res = 0;
    for (; i > 0; i -= i & -i) res += bit[i];
    return res;
}

int main(){
    freopen("virus.inp", "r", stdin);
    freopen("virus.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int inv = 0, res;
    for (int i = n; i > 0; i--){
        inv += retrieve(a[i] - 1);
        update(a[i]);
    }
    res = inv;
    for (int i = 1; i < n; i++){
        inv += n - 2 * a[i] + 1;
        res = min(res, inv);
    }
    cout << res + 2 << '\n';
}