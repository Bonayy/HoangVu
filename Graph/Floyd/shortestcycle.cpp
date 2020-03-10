#include <bits/stdc++.h>
using namespace std;

int f[150][150];
long long a[150];
int top = 0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    long long x;
    for (int i = 1; i <= n; i++){
        cin >> x; if (x > 0) a[++top] = x;
        if (top == 129){
            cout << 3; return 0;
        }
    }
    n = top; int res = n + 1;
    if (n == 0){
        cout << -1; return 0;
    }
    memset(f, 0x3f, sizeof(int) * 150 * 150);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (a[i] & a[j]) f[i][j] = 1;
    for (int i = 1; i <= n; i++) f[i][i] = 0;
    for (int k = 1; k <= n; k++){
        for (int u = 1; u <= n; u++) if (u != k && f[u][k] == 1)
            for (int v = 1; v <= n; v++) if (v != k && f[k][v] == 1)
                if (u != v) res = min(res, f[u][v] + 2);
        for (int u = 1; u <= n; u++)
            for (int v = 1; v <= n; v++) 
                f[u][v] = min(f[u][v], f[u][k] + f[k][v]);
    }
    if (res == n + 1) cout << -1;
    else cout << res;
}