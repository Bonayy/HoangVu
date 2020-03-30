#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair <int, int>;
const int N = 105;
ll dis[N][N]; 
int a[N][N], n;
int r[] = {-1, 0, 1};
int c[] = {0, 1, 0};

struct node{
    int i, j; ll w;
    bool operator < (const node &o) const {
        return w > o.w;
    }
};

bool is_node(int i, int j){
    return i > 0 && j > 0 && i <= n && j <= n;
}

ll dijkstra(int i, int j){
    memset(dis, 0x3f, sizeof(ll) * 105 * 105);
    dis[i][j] = a[i][j];
    priority_queue <node> pq;
    pq.push({i, j, a[i][j]});
    while (!pq.empty()){
        int i = pq.top().i, j = pq.top().j;
        ll dist = pq.top().w; pq.pop();
        if (dis[i][j] < dist) continue;
        if (j == n) return dist;
        for (int k = 0; k < 3; k++)
            if (is_node(i + r[k], j + c[k])){
                if (dis[i + r[k]][j + c[k]] > dis[i][j] + a[i + r[k]][j + c[k]]){
                    dis[i + r[k]][j + c[k]] = dis[i][j] + a[i + r[k]][j + c[k]];
                    pq.push({i + r[k], j + c[k], dis[i + r[k]][j + c[k]]});
                }
            }
    }
}

int main(){
    freopen("matrix.inp", "r", stdin);
    freopen("matrix.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    ll res = LLONG_MAX;
    for (int i = 1; i <= n; i++)
        res = min(res, dijkstra(i, 1));
    cout << res << '\n';
}