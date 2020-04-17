#include <bits/stdc++.h>
using namespace std;

int a[505][505], val[505], cnt[10];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("bsr.inp", "r", stdin);
    freopen("bsr.out", "w", stdout);
    int n, m, res = 0; cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++){
        for (int x = 1; x <= m; x++) val[x] = 0;
        for (int j = i; j <= n; j++){
            for (int x = 1; x <= m; x++)
                val[x] = (val[x] + a[j][x]) % 9;
            int sum = 0; cnt[0] = 1;
            fill_n(cnt + 1, 8, 0);
            for (int x = 1; x <= m; x++){
                sum = (sum + val[x]) % 9;
                res += cnt[sum]; cnt[sum]++;
            }
        }
    }
    cout << res << '\n';
}