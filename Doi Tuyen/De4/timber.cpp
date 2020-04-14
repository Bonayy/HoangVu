#include <bits/stdc++.h>
using namespace std;

const int offset = 1005;
int a[2500][2500];

int main(){
    freopen("timber.inp", "r", stdin);
    freopen("timber.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, x, y, k, maxx = 0, maxy = 0;
    cin >> n >> k; int res = 0;
    while (n--){
        cin >> x >> y; 
        x += offset; y += offset;
        a[x][y]++; maxx = max(maxx, x);
        maxy = max(maxy, y);
    }
    for (int i = 1; i <= maxx; i++)
        for (int j = 1; j <= maxy; j++){
            a[i][j] += a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1];
            int cur = a[i][j];
            if (i > k) cur -= a[i - k - 1][j];
            if (j > k) cur -= a[i][j - k - 1];
            if (i > k && j > k) cur += a[i - k - 1][j - k - 1];
            res = max(res, cur);
        }
    cout << res << '\n';
}