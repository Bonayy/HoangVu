#include <iostream>
#include <vector>
using namespace std;

namespace fastio{
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

const int N = 7e4 + 5;
int anc[18][N], spt[18][N], n;
int pow2[N], log2[N], dep[N];
vector <int> adj[N];
 
void dfs(int u, int p){
    for (int v : adj[u])
        if (v != p){
            dep[v] = dep[u] + 1; 
            dfs(v, u); anc[0][v] = u;
        }
}
 
int lca(int u, int v){
    if (dep[u] < dep[v]) return lca(v, u);
    for (int k = log2[dep[u]]; k >= 0; --k)
        if (dep[anc[k][u]] >= dep[v]) u = anc[k][u];
    if (u == v) return u;
    for (int k = log2[dep[u]]; k >= 0; --k)
        if (anc[k][u] != anc[k][v]){
            u = anc[k][u]; v = anc[k][v];
        }
    return anc[0][u];
}
 
void build_spt(){
    pow2[1] = 1; log2[1] = 0;
    for (int i = 2; i <= n; i++){
        pow2[i] = pow2[i - 1]; log2[i] = log2[i - 1];
        if ((i & (i - 1)) == 0){
            pow2[i] <<= 1; ++log2[i];
        }
    }
    for (int i = 1; i <= n; i++) spt[0][i] = i;
    dfs(1, 0); dep[0] = -1;
    for (int k = 1; k <= 17; ++k)
        for (int i = 1; i <= n; i++)
            if (log2[dep[i]] >= k)
                anc[k][i] = anc[k - 1][anc[k - 1][i]];
    for (int k = 1, p = 1; k <= 17; ++k, p <<= 1)
        for (int i = 1; i + (p << 1) <= n + 1; i++)
            spt[k][i] = lca(spt[k - 1][i], spt[k - 1][i + p]);
}
 
int query(int u, int v){
    int tmp = log2[v - u + 1];
    return lca(spt[tmp][u], spt[tmp][v + 1 - pow2[v - u + 1]]);
}
 
int main(){
    using fastio::read;
    int q, u, v; read(n); read(q);
    for (int i = 1; i < n; i++){
        read(u); read(v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    build_spt();
    while (q--){
        read(u); read(v); fastio::writeln(query(u, v));
    }
} 