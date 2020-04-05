#include <bits/stdc++.h>
using namespace std;

struct dis{
    int w, t; dis(){}
    dis(int w, int t):w(w), t(t){}
};

bool minimize(dis &a, const dis &b){
    if (a.t > b.t) 
        return a.t = b.t, a.w = b.w, 1;
    if (a.t == b.t && a.w > b.w) 
        return a.w = b.w, 1;
    return 0;
}

const int inf = 0x3f3f3f3f;
const int N = 105;
dis d[N][N];

int main(){
    freopen("input.txt", "r", stdin);
    int n, u, v, w; cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            d[i][j] = {inf, inf};
    while (cin >> u >> v >> w){
        if (w == 0) d[u][v] = {0, 1};
        else d[u][v] = d[v][u] = {w, 0};
    }
    for (int i = 1; i <= n; i++)
        d[i][i] = {0, 0};
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                minimize(d[i][j], dis(d[i][k].w + d[k][j].w, d[i][k].t + d[k][j].t));
    if (d[1][n].t == inf || d[1][n].w == inf) cout << -1;
    else cout << d[1][n].w << '\n' << d[1][n].t;
}