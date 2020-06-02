#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back
#define all(v) (v).begin(), (v).end()

struct edge{
    int u, v, w;

    edge(){}

    edge(int u, int v, int w): u(u), v(v), w(w){}

    bool operator < (const edge &o) const {
        return w < o.w;
    }
};

struct node{
    int u, par, rnk, tim;

    node(){}

    node(int u, int par, int rnk, int tim):
    u(u), par(par), rnk(rnk), tim(tim){}
};

struct presitent_dsu{
    vector <int> par, rnk; vector <node> ch;

    void init(int n){
        par.resize(n + 1); iota(all(par), 0);
        ch.clear(); rnk.resize(n + 1);
        fill(all(rnk), 0);
    }

    int find_set(int u, int tim){
        if (u != par[u]){
            ch.eb(u, par[u], rnk[u], tim);
            par[u] = find_set(par[u], tim);
        }
        return par[u];
    }

    bool union_set(int u, int v, int tim){
        u = find_set(u, tim);
        v = find_set(v, tim);
        if (u == v) return false;
        if (rnk[u] == rnk[v]){
            ch.eb(u, par[u], rnk[u], tim);
            rnk[u]++;
        }
        if (rnk[u] > rnk[v]){
            ch.eb(v, par[v], rnk[v], tim);
            par[v] = u;
        }
        else {
            ch.eb(u, par[u], rnk[u], tim);
            par[u] = v;
        }
        return true;
    }

    bool is_same_set(int u, int v, int tim){
        return find_set(u, tim) == find_set(v, tim);
    }

    void roll_back(int tim){
        while (!ch.empty() && ch.back().tim == tim){
            par[ch.back().u] = ch.back().par;
            rnk[ch.back().u] = ch.back().rnk;
            ch.pop_back();
        }
    }
} dsu;


const int inf = 0x3f3f3f3f;
const int N = 1e5 + 5;
int n, s, t, res = INT_MAX, tim;
vector <edge> a, b;

void cal(int l, int r, int optl, int optr){
    int m = (l + r) / 2, cur = ++tim;
    for (int i = l; i <= m; i++)
        dsu.union_set(a[i].u, a[i].v, cur);
    int optm = optl, nxt = ++tim;
    dsu.union_set(b[optm].u, b[optm].v, nxt);
    while (!dsu.is_same_set(s, t, nxt)){
        optm++;
        dsu.union_set(b[optm].u, b[optm].v, nxt);
    }
    if (b[optm].w != inf)
        res = min(res, a[m].w + b[optm].w);
    dsu.roll_back(nxt);
    if (m < r) cal(m + 1, r, optl, optm);
    dsu.roll_back(cur); nxt = ++tim;
    for (int i = optl; i <= optm; i++)
        dsu.union_set(b[i].u, b[i].v, nxt);
    if (l < m) cal(l, m - 1, optm, optr);
    dsu.roll_back(nxt);
}

int main(){
    freopen("bus.inp", "r", stdin);
    freopen("bus.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int m; cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++){
        int tip, u, v, w;
        cin >> tip >> u >> v >> w;
        if (tip == 1) a.eb(u, v, w);
        else b.eb(u, v, w);
    }
    a.eb(1, 1, 0); b.eb(1, 1, 0);
    for (int i = 1; i < n; i++)
        b.eb(i, i + 1, inf);
    sort(all(a)); sort(all(b)); dsu.init(n);
    cal(0, a.size() - 1, 0, b.size() - 1);
    cout << res << '\n';
}