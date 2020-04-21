#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int a[N][N]; bool col[N], row[N];

int main(){
    freopen("ant.inp", "r", stdin);
    freopen("ant.out", "w", stdout);
    int n, m, res = 0; char x; 
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++){
            cin >> x;
            if (x == '.') a[i][j] = 1;
            else col[i] = row[j] = 1;
        }
    for (int i = 1; i <= n; i++)
        if (!row[i])
            for (int j = 1; j <= m; j++){
                res += a[i][j];
                a[i][j] = 0;
            }
    for (int j = 1; j <= m; j++)
        if (!col[j])
            for (int i = 1; i <= n; i++){
                res += a[i][j];
                a[i][j] = 0;
            }
    cout << res << '\n';
}