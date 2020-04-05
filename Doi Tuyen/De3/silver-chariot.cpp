#include <bits/stdc++.h>
using namespace std;

using point = complex <double>;
const int N = 205;
int dis[N], adj[N][N], n;
point a[N]; bool used[N];


int bfs(int s, int t){
    queue <int> q; q.push(s); 
    used[s] = true;
    while (!q.empty()){
        int u = q.front(); q.pop();
        if (u == t) return dis[t];
        for (int v = 1; v <= n; v++)
            if (!used[v] && adj[u][v]){
                dis[v] = dis[u] + 1;
                used[v] = true; q.push(v);
            }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int s, t; double m, x, y;
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= n; i++){
        cin >> x >> y; a[i] = {x, y};
    }
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (abs(a[i] - a[j]) <= m)
                adj[i][j] = adj[j][i] = 1;
    cout << bfs(s, t) - 1 << '\n';
}