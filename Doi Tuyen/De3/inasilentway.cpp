#include <bits/stdc++.h>
using namespace std;

int cnt[105], a[105][105];
int p, n, m;

int solve(int c){
    int res = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            res += a[i][j] == c;
    return res;
}

int main(){
    int x1, y1, x2, y2; 
    cin >> p >> n >> m;
    set <int> color;
    for (int i = 1, c; i <= p; i++){
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        for (int x = x1 + 1; x <= x2; x++)
            for (int y = y1 + 1; y <= y2; y++)
                a[x][y] = c;
        color.insert(c);
    }
    int res = 0;
    for (int c : color) res += solve(c) == 0;
    cout << res << '\n';
    for (int c : color){
        int t = solve(c);
        if (t > 0) cout << c << ' ' << t << '\n';
    }
}