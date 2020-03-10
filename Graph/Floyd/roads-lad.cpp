#include <bits/stdc++.h>
using namespace std;

struct ope{
    int u, v, l, c;
    bool operator < (const ope& o) const {
        return c < o.c;
    }
};

int f[150][150], q[150][150];
const int inf = 0x3f3f3f3f;
ope op[10010];

bool check(int d){
    
}

int main(){
    int n, m;
    memset(f, 0x3f, sizeof f);
    memset(q, 0x3f, sizeof q);
    for (int i = 1; i <= n; i++)
        f[i][i] = 0;
    for (int i = 0, u, v, w; i < m; i++){
        cin >> u >> v >> w; 
        f[u][v] = f[v][u] = w;
    }
    int k, p; cin >> k;
    for (int i = 0; i < k; i++)
        cin >> op[i].u >> op[i].v >> op[i].l >> op[i].c;
    sort(op, op + k); cin >> p;
    for (int i = 0, u, v, w; i < p; i++){
        cin >> u >> v >> w;
        q[u][v] = q[v][u] = w;
    }
}