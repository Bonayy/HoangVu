#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int a[N], inv[N], n, pos[N], res = INT_MAX, cur;

int main(){
    freopen("virus.inp", "r", stdin);
    freopen("virus.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 1; i < n; i++){
        for (int j = 0; j < i; j++)
            if (a[j] > a[i]) inv[i]++;
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) pos[a[j]] = j;
        cur = accumulate(inv, inv + n, 0);
        if (cur == 0) return cout << 0, 0;
        for (int j = n; j >= 1; j--){
            res = min(res, cur);
            cur += 2 * pos[j] - n + 1;
        }
        for (int j = 1; j < n; j++) 
            inv[j] -= a[j] < a[0];
        inv[0] += n - a[0];
        rotate(a, a + 1, a + n);
        rotate(inv, inv + 1, inv + n);
    }
    cout << res + 2 << '\n';
}