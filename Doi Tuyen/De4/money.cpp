#include <bits/stdc++.h>
using namespace std;

const int inf = 0x3f3f3f3f;
int f[1005], g[1005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("money.inp", "r", stdin);
    freopen("money.out", "w", stdout);
    int n, s, x; cin >> n >> s;
    for (int i = 1; i <= s; i++) 
        f[i] = g[i] = inf;
    for (int i = 1; i <= n; i++){
        cin >> x;
        for (int j = x; j <= s; j++)
            g[j] = min(g[j], f[j - x] + 1);
        copy(g, g + s + 1, f);
    }
    if (f[s] == inf) puts("-1");
    else cout << f[s] << '\n';
}