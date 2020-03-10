#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m; cin >> n >> m;
    int q; cin >> q;
    int a[n + 1][m + 1];
    memset(a, 0, sizeof a);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        }
    int x1, x2, y1, y2;
    while (q--){
        cin >> x1 >> y1 >> x2 >> y2;
        cout << a[x2][y2] + a[x1 - 1][y1 - 1] -a[x2][y1 - 1] -a[x1 - 1][y2] << '\n';
    }
}
