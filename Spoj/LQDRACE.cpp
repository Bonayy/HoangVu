#define fi first
#define se second
#include <bits/stdc++.h>
using namespace std;

namespace fast_io{
    template <typename T>
    void read(T &x){
        char c; bool nega = 0; x = 0;
        while (!isdigit(c = getchar()) && c != '-');
        if (c == '-'){
            nega = 1; c = getchar();
        }
        for (; isdigit(c); c = getchar())
            x = (x << 1) + (x << 3) + c - 48;
        if (nega) x = -x;
    }

    template <typename T>
    void writep(T x){
        if (x > 9) writep(x / 10);
        putchar(x % 10 + 48);
    }

    template <typename T>
    void write(T x){
        if (x < 0){
            x = -x; putchar('-');
        }
        writep(x);
    }

    template <typename T>
    void writeln(T x){
        write(x); putchar('\n');
    }
}

struct edge{
    int v, w;
};

const int N = 2e5 + 5;
int in[N], out[N], tour[N], tim, heavy[N], dep[N], ans, n;
unordered_map <int, int> mp; int dis[N], k; vector <edge> adj[N];

void add_edge(int u, int v, int w){
    adj[u].push_back({v, w}); adj[v].push_back({u, w});
}

template <class X, class Y>
bool chkmin(X &a, const Y &b){
    return a > b ? a = b, 1 : 0;
}

int dfs_tour(int v, int p){
    int v_sz = 1, maxc_sz = 0;
    in[v] = ++tim; tour[tim] = v;
    for (auto e : adj[v]) if (e.v != p){
        dep[e.v] = dep[v] + 1; dis[e.v] = dis[v] + e.w;
        int c_sz = dfs_tour(e.v, v); v_sz += c_sz;
        if (c_sz > maxc_sz){
            maxc_sz = c_sz; heavy[v] = e.v;
        }
    }
    out[v] = tim; return v_sz;
}

void dfs_sol(int v, int p, bool cl){
    for (auto e : adj[v])
        if (e.v != p && e.v != heavy[v])
            dfs_sol(e.v, v, 1);
    if (heavy[v]) dfs_sol(heavy[v], v, 0);
    mp[dis[v]] = dep[v];
    for (auto e : adj[v])
        if (e.v != p && e.v != heavy[v]){
            for (int u = in[e.v]; u <= out[e.v]; u++){
                auto it = mp.find(dis[v] * 2 + k - dis[tour[u]]);
                if (it != mp.end()) 
                    ans = min(ans, it->se + dep[tour[u]] - 2 * dep[v]);
            }
            for (int u = in[e.v]; u <= out[e.v]; u++){
                if (mp.count(dis[tour[u]]))
                    chkmin(mp[dis[tour[u]]], dep[tour[u]]);
                else mp[dis[tour[u]]] = dep[tour[u]];   
            }
        }
    mp[dis[v]] = dep[v]; auto it = mp.find(dis[v] + k);
    if (it != mp.end()) ans = min(ans, it->second - dep[v]);
    if (cl) mp.clear();
}

int main(){
    using namespace fast_io;
    read(n); read(k); ans = n + 1;
    for (int i = 1, u, v, w; i < n; i++){
        read(u); read(v); read(w); u++; v++; add_edge(u, v, w);
    }
    dfs_tour(1, 0); dfs_sol(1, 0, 0);
    if (ans == n + 1) puts("-1"); else writeln(ans);
}