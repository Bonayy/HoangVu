#include <bits/stdc++.h>
using namespace std;

using ii = pair <int, int>;
const int N = 1e5 + 5;
const int inf = 0x3f3f3f3f;

struct segtree{
    struct node{
        int l, r, mi;
    } s[N << 2];
    
    void build(int i, int l, int r){
        s[i] = {l, r, inf};
        if (l == r) return; int m = (l + r) >> 1;
        build(i << 1, l, m); build(i << 1 | 1, m + 1, r);
    }

    void init(int n){
        build(1, 1, n);
    }

    void update(int i, int p){
        if (s[i].l > p || s[i].r < p) return;
        if (s[i].l == s[i].r){
            if (s[i].mi == inf) s[i].mi = p;
            else s[i].mi = inf; return;
        }
        update(i << 1, p); update(i << 1 | 1, p);
        s[i].mi = min(s[i << 1].mi, s[i << 1 | 1].mi);
    }

    int query(int i, int l, int r){
        if (s[i].l > r || s[i].r < l) return inf;
        if (s[i].l >= l && s[i].r <= r) return s[i].mi;
        return min(query(i << 1, l, r), query(i << 1 | 1, l, r));
    }
};

struct hld{
    int heavy[N], pos[N], head[N], par[N], dep[N], tim;
    segtree st; vector <int> adj[N]; int ver[N];

    void add_edge(int u, int v){
        adj[u].push_back(v); adj[v].push_back(u);
    }

    int dfs_tour(int v){
        int v_sz = 1, maxc_sz = 0;
        for (int c : adj[v]) if (c != par[v]){
            par[c] = v; dep[c] = dep[v] + 1;
            int c_sz = dfs_tour(c); v_sz += c_sz;
            if (c_sz > maxc_sz){
                maxc_sz = c_sz; heavy[v] = c;
            }
        }
        return v_sz;
    }

    void dfs_hld(int v, int h){
        head[v] = h; pos[v] = ++tim; ver[tim] = v;
        if (heavy[v]) dfs_hld(heavy[v], h);
        for (int c : adj[v]) 
            if (c != par[v] && c != heavy[v])
                dfs_hld(c, c);
    }

    void update(int u){
        st.update(1, pos[u]);
    }

    int query(int u){
        int res = inf;
        while (head[u] != 1){
            res = min(res, st.query(1, pos[head[u]], pos[u]));
            u = par[head[u]];
        }
        res = min(res, st.query(1, 1, pos[u]));
        if (res == inf) return -1; return ver[res];
    }

    void solve(){
        int n, q; cin >> n >> q; st.init(n); tim = 0;
        for (int i = 1; i <= n; i++){
            par[i] = head[i] = dep[i] = pos[i] = heavy[i] = 0;
            adj[i].clear();
        }
        for (int i = 1, u, v; i < n; i++){
            cin >> u >> v; add_edge(u, v);
        }
        dfs_tour(1); dfs_hld(1, 1); int cmd, v;
        while (q--){
            cin >> cmd >> v;
            if (cmd) cout << query(v) << '\n'; else update(v);
        }
    }
} g;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); g.solve();
}